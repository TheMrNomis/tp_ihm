#ifndef ABSTRACTPRESENTER_H
#define ABSTRACTPRESENTER_H

#include <QObject>
#include <AbstractModel.h>
#include <AbstractParameterWidget.h>
#include <GraphicsImageScene.h>
#include "ImageConverter.h"

class MainWindow;

class AbstractPresenter : public QObject
{
  Q_OBJECT
public:
  explicit AbstractPresenter(MainWindow *parent,
                             AbstractModel * model,
                             AbstractParameterWidget * parameterWidget,
                             GraphicsImageScene * inputScene,
                             GraphicsImageScene * resultScene);

signals:

private slots:
  virtual void runModel() = 0;
  virtual void presentModelResults() = 0;

protected:
  MainWindow * m_parent;
  AbstractModel * m_model;
  AbstractParameterWidget * m_parameterWidget;
  GraphicsImageScene * m_inputScene;
  GraphicsImageScene * m_resultScene;
};

#endif // ABSTRACTPRESENTER_H
