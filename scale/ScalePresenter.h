#ifndef SCALEPRESENTER_H
#define SCALEPRESENTER_H

#include "../AbstractPresenter.h"

#include "ScaleModel.h"
#include "ScaleParameterWidget.h"

class ScalePresenter : public AbstractPresenter
{
public:
  ScalePresenter(MainWindow *parent,
                 ScaleModel * model,
                 ScaleParameterWidget * parametersWidget,
                 GraphicsImageScene * inputScene,
                 GraphicsImageScene * resultScene);


private slots:
  virtual void runModel();
  virtual void presentModelResults();

private:
  ScaleModel * m_scaleModel;
  ScaleParameterWidget * m_scaleParameterWidget;
};

#endif // SCALEPRESENTER_H
