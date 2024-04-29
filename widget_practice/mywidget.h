#pragma once

#include <QWidget>
#include <QOpenGLWidget>
class MyWidget : public QOpenGLWidget
{
public:
protected:
	virtual void paintGL() override;
};