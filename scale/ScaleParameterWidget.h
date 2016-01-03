#ifndef SCALEPARAMETERWIDGET_H
#define SCALEPARAMETERWIDGET_H

#include "../AbstractParameterWidget.h"

#include <QDoubleSpinBox>

class ScaleParameterWidget : public AbstractParameterWidget
{
public:
  ScaleParameterWidget(QWidget * parent = 0);

  double getFactor() const;

private:
  QDoubleSpinBox * m_factor;
};

#endif // SCALEPARAMETERWIDGET_H
