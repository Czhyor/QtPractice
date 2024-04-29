#include "mymainwindow.h"
#include "./ui_mainwindow.h"

MyMainWindow::MyMainWindow(QWidget* parent):
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}
MyMainWindow::~MyMainWindow()
{
	delete ui;
}