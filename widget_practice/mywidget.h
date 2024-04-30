#pragma once

#include <QWidget>
#include <QOpenGLWidget>
#include <QThread>
#include <QElapsedTimer>
#include <QTimer>

class WorkThread : public QThread
{
public:
protected:
	virtual void run() override;
};

class ComputeBackgroundColorOpe : public QObject
{
	Q_OBJECT
public:
signals:
	void computeFinished(float red, float green, float blue);
public slots:
	void onExecute();
};

class Animation : public QObject
{
public:
	Animation(int msInterval) : m_interval(msInterval) {}

	void update();
protected:
	virtual void updateImplementation(int ratio) = 0;
private:
	QElapsedTimer m_timer;
	int m_interval;
};

class MyWidget : public QOpenGLWidget
{
public:
	MyWidget();
	~MyWidget();

	void changeBackgroundColor();

	void addAnimation(QSharedPointer<Animation> animation);

protected:
	virtual void paintGL() override;
	void updateAnimation();

private:
	float m_red = 1.0, m_green = 1.0, m_blue = 1.0;
	WorkThread m_workThread;

	ComputeBackgroundColorOpe m_computeBkColor;

	QVector<QSharedPointer<Animation>> m_animations;
	QTimer m_animationTimerControl;
};