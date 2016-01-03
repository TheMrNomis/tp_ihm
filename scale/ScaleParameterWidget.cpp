#include "ScaleParameterWidget.h"

ScaleParameterWidget::ScaleParameterWidget(QWidget * parent):
  AbstractParameterWidget("Scale", parent),
  m_factor(new QDoubleSpinBox(this))
{
  m_factor->setAccelerated(true);
  m_factor->setDecimals(1);
  m_factor->setRange(0.1, 10);
  m_factor->setValue(1);
  m_factor->setSingleStep(0.1);

  m_parametersLayout->addRow("Scale Factor :", m_factor);
}

double ScaleParameterWidget::getFactor() const
{
  return m_factor->value();
}
