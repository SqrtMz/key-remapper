#pragma once

#include "input-listener.hpp"
#include <set>
#include <atomic>
#include <libevdev/libevdev-uinput.h>
#include <QDebug>
#include <QThread>

class VirtualDeviceWorker : public QObject {
	Q_OBJECT

	public:
		VirtualDeviceWorker(const std::string& device_path, std::atomic<bool>& input_listener_exists, QObject* parent = nullptr);

	public slots:
		void start();
		void stop();
		
	private:
		std::string m_device_path;
		std::atomic<bool> m_is_listening;
		std::atomic<bool>& m_input_listener_exists; // If input listener exists, then the local listener will ungrab the device, when it gets deleted, local listener will regrab the device inputs.

	signals:
		void send_key_events(int code, int value);
		void finished();
};


class VirtualDevice : public QObject {
	Q_OBJECT

	public:
		VirtualDevice(const std::string& device_path, std::atomic<bool>& input_listener_exists, QObject* parent = nullptr);
		virtual ~VirtualDevice();

		void start();
		void stop();
		
		VirtualDeviceWorker* m_vd_worker;

	protected:
		struct libevdev_uinput* m_uinput = nullptr;
		std::string m_device_path;
		QThread* m_worker_thread;

		virtual void generate_key_event(int code, int value) {};
		virtual void generate_abs_event(int axis, int value) {};
		virtual void generate_rel_event(int code, int value) {};
		
	protected slots:
		virtual void handle_key_events(int code, int value) {};
};