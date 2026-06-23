#pragma once

#include <atomic>
#include <QWidget>
#include <QList>
#include "label-button.hpp"
#include "core/input-listener.hpp"
#include "core/device-events.hpp"
#include "core/virtual-controller.hpp"

class ControllerView : public QWidget {
	Q_OBJECT

	public:
		ControllerView(std::string& selected_device, QWidget* parent = nullptr);

		/**
		* When this function is triggered, it creates a VirtualDevice object, and starts it immediately.
		* What this causes is that the device initializes a new thread and a worker that will run in the background in order to start listening for the new input events of the physical device.
		* Also changes the enable state of the start and stop buttons.
		*/
		void start();

		// Stops what start() starts... Who'd think it, right?
		void stop();
	
		std::string& m_selected_device;
		LabelButton* m_selected_label_button = nullptr;
		InputListener* m_input_listener = nullptr;
		std::atomic<bool> m_input_listener_exists = false;
		
		struct controller_events m_events;
		VirtualController* m_virtual_controller_dev = nullptr;

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
};