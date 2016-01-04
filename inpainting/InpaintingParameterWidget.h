#ifndef INPAINTINGPARAMETERWIDGET_H
#define INPAINTINGPARAMETERWIDGET_H

#include "AbstractParameterWidget.h"

#include <QSpinBox>
#include <QPushButton>

class InpaintingParameterWidget : public AbstractParameterWidget
{
public:
    InpaintingParameterWidget(QWidget * parent = 0);

    // methodes
    int getSize() const;


private:
    QButtonGroup * m_brush;

    QPushButton * m_circle;
    QPushButton * m_square;

    QSpinBox * m_size;
};

#endif // INPAINTINGPARAMETERWIDGET_H
