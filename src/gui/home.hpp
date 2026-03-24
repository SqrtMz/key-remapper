#pragma once

#include "label-button.hpp"
#include "core/input-listener.hpp"
#include "core/virtual-controller.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <QMainWindow>
#include <QString>
#include <QProcess>
#include <QPushButton>
#include <QSystemTrayIcon>
#include <QKeyEvent>
#include <QCloseEvent>

class Home : public QMainWindow {
	Q_OBJECT

	public:
		Home(QWidget* parent = nullptr);
		
		protected:
		// Causes the program to ignore the window closed event, avoiding that the programs stop there.
		void closeEvent(QCloseEvent* event) override;
		
		private:
		QSystemTrayIcon *m_tray;
		std::string m_selected_device;
		QMenu* m_file_menu;
		QMenu* m_devices_menu;
		VirtualController* m_virtual_controller_dev;
		QProcess* m_proc;
		QPushButton* m_start_button;
		QPushButton* m_stop_button;
		InputListener* m_input_listener = nullptr;
		std::atomic<bool> m_input_listener_exists = false;
		LabelButton* m_selected_label_button = nullptr;
		struct controller_events m_events;
		
	private slots:
		/**
		 * When a LabelButton button is clicked, it creates a InputListener which starts a new thread
		 * and starts listening events until a release key event is received. Then emits the pressed
		 * keys at the moment to receive_detected_keys().
		 */
		void start_key_listener (LabelButton* lb);

		/**
		 * Receives the data emitted by the send_detected_keys() on the InputListener and
		 * saves the key combination on to the LabelButtons attributes.
		 */
		void recieve_detected_keys(QList<int> keys);

		/**
		 * Clear the devices menu and then check all the valid devices (event type) on /dev,
		 * then create an entry for each device on the menu and set the click event to select
		 * the device that will be worked on.
		 */
		void reload_devices();

		/**
		* When this function is triggered, it creates a VirtualDevice object, and starts it immediately.
		* What this causes is that the device initializes a new thread and a worker that will run in the background in order to start listening for the new input events of the physical device.
		* Also changes the enable state of the start and stop buttons.
		*/
		void start();

		// Stops what start() starts... Who'd think it, right?
		void stop();
};