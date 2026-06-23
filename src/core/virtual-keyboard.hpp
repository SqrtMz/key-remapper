#pragma once

#include "input-listener.hpp"
#include "virtual-device.hpp"
#include "device-events.hpp"
#include <libevdev/libevdev-uinput.h>

class VirtualKeyboard : public VirtualDevice {
	Q_OBJECT

	public:
		VirtualKeyboard(const std::string& device_path, struct keyboard_events& events, std::atomic<bool>& input_listener_exists, QObject* parent = nullptr);

		void generate_key_event(int code, int value) override;

		protected slots:
			void handle_key_events(int code, int value) override;

		private:
			std::set<int> m_held_keys;
			struct keyboard_events m_events;
};