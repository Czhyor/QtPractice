#include "mywidget.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions>

void WorkThread::run()
{
    qDebug() << "WorkThread::run";
    exec();
}

void ComputeBackgroundColorOpe::onExecute()
{
    float red = float(rand()) / RAND_MAX;
    float green = float(rand()) / RAND_MAX;
    float blue = float(rand()) / RAND_MAX;
    emit computeFinished(red, green, blue);
}

void Animation::update()
{
    int interval = m_timer.elapsed();
    float ratio = (float)interval / m_interval;
    updateImplementation(ratio);
}

MyWidget::MyWidget()
{
    m_workThread.start();

    connect(&m_computeBkColor, &ComputeBackgroundColorOpe::computeFinished, this, [this](float red, float green, float blue) {
        m_red = red; m_green = green; m_blue = blue;
        update();
    });
    m_computeBkColor.moveToThread(&m_workThread);


    m_animationTimerControl.setSingleShot(false);
    m_animationTimerControl.setInterval(10);
    connect(&m_animationTimerControl, &QTimer::timeout, this, [this]() {
        
    });
    m_animationTimerControl.start();
}

MyWidget::~MyWidget()
{

}

void MyWidget::changeBackgroundColor()
{
    QMetaObject::invokeMethod(&m_computeBkColor, &ComputeBackgroundColorOpe::onExecute);
}

void MyWidget::addAnimation(QSharedPointer<Animation> animation)
{
    m_animations.push_back(animation);
}

void MyWidget::updateAnimation()
{
    for (auto& animation : m_animations) {
        animation->update();
    }
}

void MyWidget::paintGL()
{
    //Q_D(QOpenGLWidget);
    //if (d->initialized)
    //    d->context->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    context()->functions()->glClearColor(m_red, m_green, m_blue, 1.0);
    context()->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}