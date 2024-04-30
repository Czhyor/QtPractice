#include <QApplication>
#include <QPushButton>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QThread>
#include "mymainwindow.h"
#include "mywidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	MyMainWindow mw;
	mw.setGeometry(100, 100, 960, 640);
	mw.show();

	QMenuBar* menuBar = mw.menuBar();
	menuBar->addMenu(QString("Project"));
	menuBar->addMenu(QString("Edit"));

	MyWidget* central = new MyWidget;
	central->setStyleSheet("background-color: green;");

	QWidget* vLayoutWidget = new QWidget(central);
	vLayoutWidget->setGeometry(100, 100, 150, 150);

	QPushButton* button = new QPushButton(vLayoutWidget);
	button->setText("press");
	button->setStyleSheet(QString::fromUtf8("background-image: url(:/testpicture.png);"));
	button->show();
	QObject::connect(button, &QPushButton::clicked, []() {
		qDebug() << "button clicked";
	});


	QPushButton* button2 = new QPushButton(vLayoutWidget);
	button2->setText("press2");
	button2->show();
	QObject::connect(button2, &QPushButton::clicked, [&]() {
		qDebug() << "button2 clicked";
		central->changeBackgroundColor();
	});

	QVBoxLayout* vLayout = new QVBoxLayout(vLayoutWidget);
	vLayout->setGeometry(QRect(0, 0, 100, 100));
	vLayout->addWidget(button);
	vLayout->addWidget(button2);

	mw.setCentralWidget(central);
	return app.exec();
}