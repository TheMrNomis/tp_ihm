#ifndef INPAINTINGPRESENTER_H
#define INPAINTINGPRESENTER_H

#include "../AbstractPresenter.h"

#include "InpaintingModel.h"
#include "InpaintingParameterWidget.h"

class InpaintingPresenter : public AbstractPresenter
{
public:
    InpaintingPresenter(MainWindow *parent,
                        InpaintingModel * model,
                        InpaintingParameterWidget * parameterWidget,
                        GraphicsImageScene * inputScene,
                        GraphicsImageScene * resultScene);

    virtual void runModel();
    virtual void presentModelResults();
};

#endif // INPAINTINGPRESENTER_H
