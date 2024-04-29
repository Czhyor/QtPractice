#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}

class MyMainWindow : public QMainWindow
{
public:
	MyMainWindow(QWidget* parent = nullptr);
	~MyMainWindow();
private:
	Ui::MainWindow* ui;
};