#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <QMainWindow>
#include <QString>
#include <QProcess>
#include <QPushButton>
#include <QSystemTrayIcon>

class Home : public QMainWindow {

	Q_OBJECT

	public:
		Home();
		QSystemTrayIcon *tray;
		
	private:
	QString selected_device;
	QMenu *file_menu;
	QMenu *devices_menu;
	QProcess *proc;
	QPushButton *start_button;
	QPushButton *stop_button;
	
	private slots:
	void assign_key ();
	void reload_devices();
	void start();
	void stop();
	void closeEvent(QCloseEvent *event) override;
	void keyPressEvent(const QKeyEvent *event) override;
};