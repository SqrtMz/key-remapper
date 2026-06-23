#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QSystemTrayIcon>
#include <QKeyEvent>
#include <QCloseEvent>
#include <QTabWidget>
#include "label-button.hpp"
#include "controller-view.hpp"
#include "keyboard-view.hpp"

class Home : public QMainWindow {
	Q_OBJECT

	public:
		Home(QWidget* parent = nullptr);
		
	protected:
		// Causes the program to ignore the window closed event, avoiding that the programs stop there.
		void closeEvent(QCloseEvent* event) override;
	
	private:
		QMenu* m_file_menu;
		QMenu* m_devices_menu;
		std::string m_selected_device;

		QSystemTrayIcon *m_tray;

		QTabWidget* m_tab_menu;

		ControllerView* m_controller_view;
		KeyboardView* m_keyboard_view;

		QPushButton* m_start_button;
		QPushButton* m_stop_button;
		
	private slots:
		/**
		 * Clear the devices menu and then check all the valid devices (event type) on /dev,
		 * then create an entry for each device on the menu and set the click event to select
		 * the device that will be worked on.
		 */
		void reload_devices();

		/**
		 * Start the virtual device within the device view widget class
		 */
		void start();

		/**
		 * Stops the magic of start() as you guessed it
		 */
		void stop();
};