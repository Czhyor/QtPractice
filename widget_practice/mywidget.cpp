#include "mywidget.h"
#include <QOpenGLContext>
#include <QOpenGLFunctions>
void MyWidget::paintGL()
{
    //Q_D(QOpenGLWidget);
    //if (d->initialized)
    //    d->context->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    context()->functions()->glClearColor(0.0, 1.0, 0.0, 1.0);
    context()->functions()->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}