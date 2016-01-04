#include "InpaintingParameterWidget.h"

InpaintingParameterWidget::InpaintingParameterWidget(QWidget *parent):
    AbstractParameterWidget("Inpainting",parent),
    m_brush(new QButtonGroup(this)),
    m_circle(new QPushButton(this)),
    m_square (new QPushButton(this)),
    m_size(new QSpinBox(this))
{
    m_brush->addButton(m_circle,1);
    m_brush->addButton(m_square,2);

}

int InpaintingParameterWidget::getSize() const
{
    return m_size->value();
}
