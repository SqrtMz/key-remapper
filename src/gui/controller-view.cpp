#include "controller-view.hpp"
#include <iostream>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QThread>

ControllerView::ControllerView(std::string& selected_device, QWidget* parent) : QWidget(parent), m_selected_device(selected_device) {

	QFormLayout* layout = new QFormLayout();
	this->setLayout(layout);

	LabelButton* btn_west = new LabelButton("Y", "No key assigned");
	layout->addRow(btn_west);
	connect(btn_west->button, &QPushButton::clicked, this, [this, btn_west](){start_key_listener(btn_west);});
	m_events.btn_west = &btn_west->key_code;
	
	LabelButton* btn_east = new LabelButton("B", "No key assigned");
	layout->addRow(btn_east);
	connect(btn_east->button, &QPushButton::clicked, this, [this, btn_east](){start_key_listener(btn_east);});
	m_events.btn_east = &btn_east->key_code;
	
	LabelButton* btn_south = new LabelButton("A", "No key assigned");
	layout->addRow(btn_south);
	connect(btn_south->button, &QPushButton::clicked, this, [this, btn_south](){start_key_listener(btn_south);});
	m_events.btn_south = &btn_south->key_code;

	LabelButton* btn_north = new LabelButton("X", "No key assigned");
	layout->addRow(btn_north);
	connect(btn_north->button, &QPushButton::clicked, this, [this, btn_north](){start_key_listener(btn_north);});
	m_events.btn_north = &btn_north->key_code;
	
	LabelButton* btn_dpad_up = new LabelButton("Dpad Up", "No key assigned");
	layout->addRow(btn_dpad_up);
	connect(btn_dpad_up->button, &QPushButton::clicked, this, [this, btn_dpad_up](){start_key_listener(btn_dpad_up);});
	m_events.btn_dpad_up = &btn_dpad_up->key_code;

	LabelButton* btn_dpad_right = new LabelButton("Dpad Right", "No key assigned");
	layout->addRow(btn_dpad_right);
	connect(btn_dpad_right->button, &QPushButton::clicked, this, [this, btn_dpad_right](){start_key_listener(btn_dpad_right);});
	m_events.btn_dpad_right = &btn_dpad_right->key_code;

	LabelButton* btn_dpad_down = new LabelButton("Dpad Down", "No key assigned");
	layout->addRow(btn_dpad_down);
	connect(btn_dpad_down->button, &QPushButton::clicked, this, [this, btn_dpad_down](){start_key_listener(btn_dpad_down);});
	m_events.btn_dpad_down = &btn_dpad_down->key_code;

	LabelButton* btn_dpad_left = new LabelButton("Dpad Left", "No key assigned");
	layout->addRow(btn_dpad_left);
	connect(btn_dpad_left->button, &QPushButton::clicked, this, [this, btn_dpad_left](){start_key_listener(btn_dpad_left);});
	m_events.btn_dpad_left = &btn_dpad_left->key_code;

	LabelButton* btn_start = new LabelButton("Start", "No key assigned");
	layout->addRow(btn_start);
	connect(btn_start->button, &QPushButton::clicked, this, [this, btn_start](){start_key_listener(btn_start);});
	m_events.btn_start = &btn_start->key_code;

	LabelButton* btn_mode = new LabelButton("Brand Button", "No key assigned");
	layout->addRow(btn_mode);
	connect(btn_mode->button, &QPushButton::clicked, this, [this, btn_mode](){start_key_listener(btn_mode);});
	m_events.btn_mode = &btn_mode->key_code;

	LabelButton* btn_select = new LabelButton("Select", "No key assigned");
	layout->addRow(btn_select);
	connect(btn_select->button, &QPushButton::clicked, this, [this, btn_select](){start_key_listener(btn_select);});
	m_events.btn_select = &btn_select->key_code;

	LabelButton* btn_tl = new LabelButton("LB", "No key assigned");
	layout->addRow(btn_tl);
	connect(btn_tl->button, &QPushButton::clicked, this, [this, btn_tl](){start_key_listener(btn_tl);});
	m_events.btn_tl = &btn_tl->key_code;

	LabelButton* btn_tr = new LabelButton("RB", "No key assigned");
	layout->addRow(btn_tr);
	connect(btn_tr->button, &QPushButton::clicked, this, [this, btn_tr](){start_key_listener(btn_tr);});
	m_events.btn_tr = &btn_tr->key_code;

	LabelButton* btn_tl2 = new LabelButton("LT", "No key assigned");
	layout->addRow(btn_tl2);
	connect(btn_tl2->button, &QPushButton::clicked, this, [this, btn_tl2](){start_key_listener(btn_tl2);});
	m_events.btn_tl2 = &btn_tl2->key_code;

	LabelButton* btn_tr2 = new LabelButton("RT", "No key assigned");
	layout->addRow(btn_tr2);
	connect(btn_tr2->button, &QPushButton::clicked, this, [this, btn_tr2](){start_key_listener(btn_tr2);});
	m_events.btn_tr2 = &btn_tr2->key_code;

	LabelButton* btn_ljoy_up = new LabelButton("L-Joystick Up", "No key assigned");
	layout->addRow(btn_ljoy_up);
	connect(btn_ljoy_up->button, &QPushButton::clicked, this, [this, btn_ljoy_up](){start_key_listener(btn_ljoy_up);});
	m_events.abs_ljoy_up = &btn_ljoy_up->key_code;

	LabelButton* btn_ljoy_right = new LabelButton("L-Joystick Right", "No key assigned");
	layout->addRow(btn_ljoy_right);
	connect(btn_ljoy_right->button, &QPushButton::clicked, this, [this, btn_ljoy_right](){start_key_listener(btn_ljoy_right);});
	m_events.abs_ljoy_right = &btn_ljoy_right->key_code;

	LabelButton* btn_ljoy_down = new LabelButton("L-Joystick Down", "No key assigned");
	layout->addRow(btn_ljoy_down);
	connect(btn_ljoy_down->button, &QPushButton::clicked, this, [this, btn_ljoy_down](){start_key_listener(btn_ljoy_down);});
	m_events.abs_ljoy_down = &btn_ljoy_down->key_code;

	LabelButton* btn_ljoy_left = new LabelButton("L-Joystick Left", "No key assigned");
	layout->addRow(btn_ljoy_left);
	connect(btn_ljoy_left->button, &QPushButton::clicked, this, [this, btn_ljoy_left](){start_key_listener(btn_ljoy_left);});
	m_events.abs_ljoy_left = &btn_ljoy_left->key_code;

	LabelButton* btn_lthumb = new LabelButton("L-Joystick Button", "No key assigned");
	layout->addRow(btn_lthumb);
	connect(btn_lthumb->button, &QPushButton::clicked, this, [this, btn_lthumb](){start_key_listener(btn_lthumb);});
	m_events.btn_thumbl = &btn_lthumb->key_code;

	LabelButton* btn_rjoy_up = new LabelButton("R-Joystick Up", "No key assigned");
	layout->addRow(btn_rjoy_up);
	connect(btn_rjoy_up->button, &QPushButton::clicked, this, [this, btn_rjoy_up](){start_key_listener(btn_rjoy_up);});
	m_events.abs_rjoy_up = &btn_rjoy_up->key_code;

	LabelButton* btn_rjoy_right = new LabelButton("R-Joystick Right", "No key assigned");
	layout->addRow(btn_rjoy_right);
	connect(btn_rjoy_right->button, &QPushButton::clicked, this, [this, btn_rjoy_right](){start_key_listener(btn_rjoy_right);});
	m_events.abs_rjoy_right = &btn_rjoy_right->key_code;

	LabelButton* btn_rjoy_down = new LabelButton("R-Joystick Down", "No key assigned");
	layout->addRow(btn_rjoy_down);
	connect(btn_rjoy_down->button, &QPushButton::clicked, this, [this, btn_rjoy_down](){start_key_listener(btn_rjoy_down);});
	m_events.abs_rjoy_down = &btn_rjoy_down->key_code;

	LabelButton* btn_rjoy_left = new LabelButton("R-Joystick Left", "No key assigned");
	layout->addRow(btn_rjoy_left);
	connect(btn_rjoy_left->button, &QPushButton::clicked, this, [this, btn_rjoy_left](){start_key_listener(btn_rjoy_left);});
	m_events.abs_rjoy_left = &btn_rjoy_left->key_code;

	LabelButton* btn_rthumb = new LabelButton("R-Joystick Button", "No key assigned");
	layout->addRow(btn_rthumb);
	connect(btn_rthumb->button, &QPushButton::clicked, this, [this, btn_rthumb](){start_key_listener(btn_rthumb);});
	m_events.btn_thumbr = &btn_rthumb->key_code;
}

void ControllerView::start_key_listener(LabelButton* lb) {

	if (m_selected_device == "") return;

	if (m_input_listener) {
		m_input_listener->stop();
		m_input_listener = nullptr;
	}

	lb->button->setText("Waiting for key...");
	m_selected_label_button = lb;

	m_input_listener = new InputListener(m_selected_device, this);
	m_input_listener_exists = true;

	connect(m_input_listener, &InputListener::send_detected_keys, this, &ControllerView::recieve_detected_keys);
	connect(m_input_listener, &QThread::finished, m_input_listener, &QThread::deleteLater);

	m_input_listener->start();
}

void ControllerView::recieve_detected_keys(QList<int> keys) {
	
	if (m_selected_label_button) {

		m_selected_label_button->key_code = QList<int>() << 0;

		if (keys.size() < 1) {
			m_selected_label_button->button->setText("No key assigned");
			return;
		}

		QString text;

		for (int k : keys) {
			text.append(libevdev_event_code_get_name(EV_KEY, k));
			text.append(" + ");
		}
		text.chop(3);

		m_selected_label_button->button->setText(text);
		m_selected_label_button->key_code = keys;

		m_selected_label_button = nullptr;
		m_input_listener = nullptr;
		m_input_listener_exists = false;
		text.clear();
	}
}

void ControllerView::start() {
	m_virtual_controller_dev = new VirtualController(m_selected_device, m_events, m_input_listener_exists, this);
	m_virtual_controller_dev->start();
}

void ControllerView::stop() {
	if (m_virtual_controller_dev) {
		m_virtual_controller_dev->stop();
		delete m_virtual_controller_dev;
		m_virtual_controller_dev = nullptr;
	}
}