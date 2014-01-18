
#ifndef LCDWIDGETINSPECTOR_H
#define LCDWIDGETINSPECTOR_H

#include <gammaray/core/toolfactory.h>

#include <QGLWidget>

class QtOpenGLSupport : public QObject
{
  Q_OBJECT
public:
  explicit QtOpenGLSupport(GammaRay::ProbeInterface *probe, QObject *parent = 0);
};

class QtOpenGLSupportFactory : public QObject, public GammaRay::StandardToolFactory<QGLWidget, QtOpenGLSupport>
{
  Q_OBJECT
  Q_INTERFACES(GammaRay::ToolFactory)
  Q_PLUGIN_METADATA(IID "com.kdab.gammaray.QtOpenGLSupport")

public:
  explicit QtOpenGLSupportFactory(QObject *parent = 0) : QObject(parent)
  {
  }

  inline QString name() const Q_DECL_OVERRIDE
  {
    return tr("QtOpenGL Support");
  }

};

#endif
