#include "home.hpp"
#include <cstdlib>
#include <fcntl.h>
#include <dirent.h>
#include <csignal>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QFormLayout>
#include <QLabel>
#include <QTabWidget>
#include <QLabel>
#include <QScrollArea>
#include <libevdev/libevdev.h>
#include "controller-view.hpp"

int is_event_device(const struct dirent* dev) {
	return strncmp("event", dev->d_name, 5) == 0;
}

Home::Home(QWidget* parent) : QMainWindow(parent) {
	setWindowTitle("Evsieve Wrapper");

	m_tray = new QSystemTrayIcon(QIcon::fromTheme("application-system"), this);
	QMenu* tray_menu = new QMenu(this);

	QAction* tray_show = tray_menu->addAction("Show");
	connect(tray_show, &QAction::triggered, this, &Home::show);
	
	QAction* tray_quit = tray_menu->addAction("Quit");
	connect(tray_quit, &QAction::triggered, this, &QApplication::quit);

	m_tray->setContextMenu(tray_menu);
	m_tray->show();

	m_file_menu = menuBar()->addMenu("&File");
	
	QAction* quit_action = m_file_menu->addAction("Quit");
	connect(quit_action, &QAction::triggered, this, &QApplication::quit);
	
	m_devices_menu = menuBar()->addMenu("&Devices");
	connect(m_devices_menu, &QMenu::aboutToShow, this, &Home::reload_devices);
	
	QWidget* w = new QWidget(this);
	setCentralWidget(w);
	
	QVBoxLayout* layout = new QVBoxLayout(w);
	m_tab_menu = new QTabWidget();

	m_controller_view = new ControllerView(m_selected_device);

	QScrollArea* controller_scroll_area = new QScrollArea();
	controller_scroll_area->setWidgetResizable(true);
	controller_scroll_area->setWidget(m_controller_view);

	m_tab_menu->addTab(controller_scroll_area, "Controller");

	m_keyboard_view = new KeyboardView(m_selected_device);

	QScrollArea* keyboard_scroll_area = new QScrollArea();
	keyboard_scroll_area->setWidgetResizable(true);
	keyboard_scroll_area->setWidget(m_keyboard_view);

	m_tab_menu->addTab(keyboard_scroll_area, "Keyboard");

	layout->addWidget(m_tab_menu);

	QHBoxLayout* bottom_layout = new QHBoxLayout();
	layout->addLayout(bottom_layout);

	m_start_button = new QPushButton("Start");
	bottom_layout->addWidget(m_start_button);
	connect(m_start_button, &QPushButton::clicked, this, &Home::start);

	m_stop_button = new QPushButton("Stop");
	m_stop_button->setDisabled(true);
	bottom_layout->addWidget(m_stop_button);
	connect(m_stop_button, &QPushButton::clicked, this, &Home::stop);
}

void Home::closeEvent(QCloseEvent* event) {
	hide();
	event->ignore();
}

void Home::reload_devices() {

	m_devices_menu->clear();

	struct dirent** devices;
	int num_devs = scandir("/dev/input", &devices, is_event_device, versionsort);

	if (num_devs <= 0) {m_devices_menu->addAction("No devices available")->setDisabled(true);}
	else {
		for (int i = 0; i < num_devs; i++) {

			struct libevdev* dev = nullptr;
			std::string event_path = "/dev/input/" + (std::string)devices[i]->d_name;
			int fd = ::open(event_path.c_str(), O_RDONLY | O_NONBLOCK);

			if (fd < 0) return;

			int rc = libevdev_new_from_fd(fd, &dev);
			if (rc < 0) {
				::close(fd);
				return;
			}

			if (rc == 0) {
				std::string name = libevdev_get_name(dev);
				std::string action_name = name + '\t' + event_path;

				QAction* tmp_action = m_devices_menu->addAction(action_name.c_str());
				connect(tmp_action, &QAction::triggered, this, [this, event_path](bool checked){m_selected_device = event_path;});
			}

			libevdev_free(dev);
			::close(fd);
		}
	}
}

void Home::start() {
	if (m_tab_menu->currentIndex() == 0) m_controller_view->start();
	else if (m_tab_menu->currentIndex() == 1) m_keyboard_view->start();

	m_start_button->setDisabled(true);
	m_stop_button->setDisabled(false);
}

void Home::stop() {
	m_controller_view->stop();
	m_keyboard_view->stop();

	m_start_button->setDisabled(false);
	m_stop_button->setDisabled(true);
}