#ifndef ROTATIONPRESENTER_H
#define ROTATIONPRESENTER_H

#include "../AbstractPresenter.h"
#include "RotationModel.h"
#include "RotationParameterWidget.h"

class RotationPresenter : public AbstractPresenter
{
public:
  RotationPresenter(MainWindow *parent,
                    RotationModel * model,
                    RotationParameterWidget * parametersWidget,
                    GraphicsImageScene * inputScene,
                    GraphicsImageScene * resultScene);

private slots:
  virtual void runModel();
  virtual void presentModelResults();

private:
  RotationModel * m_rotationModel;
  RotationParameterWidget * m_rotationParameterWidget;
};

#endif // ROTATIONPRESENTER_H
