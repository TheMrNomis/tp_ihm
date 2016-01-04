#include "InpaintingParameterWidget.h"

InpaintingParameterWidget::InpaintingParameterWidget(DrawableGraphicsScene * scene, QWidget *parent):
    AbstractParameterWidget("Inpainting",parent),
    m_scene(scene),
    m_brushGroupBox(new QGroupBox("Brush shape", this)),
    m_brushButtonGroup(new QButtonGroup()),
    m_circleBrushButton(new QPushButton("circle", m_brushGroupBox)),
    m_squareBrushButton(new QPushButton("square", m_brushGroupBox)),
    m_brushSize(new QSpinBox(this))
{
  m_circleBrushButton->setCheckable(true);
  m_squareBrushButton->setCheckable(true);

  m_brushButtonGroup->setExclusive(true);

  m_brushButtonGroup->addButton(m_circleBrushButton);
  m_brushButtonGroup->addButton(m_squareBrushButton);

  QHBoxLayout * brushButtonsLayout = new QHBoxLayout;
  brushButtonsLayout->addWidget(m_circleBrushButton);
  brushButtonsLayout->addWidget(m_squareBrushButton);
  m_brushGroupBox->setLayout(brushButtonsLayout);

  m_parametersLayout->addRow(m_brushGroupBox);
  m_parametersLayout->addRow("Size :", m_brushSize);

  QObject::connect(m_circleBrushButton, SIGNAL(pressed()), this, SLOT(setCircleBrushShape()));
  QObject::connect(m_squareBrushButton, SIGNAL(pressed()), this, SLOT(setSquareBrushShape()));

  m_circleBrushButton->setChecked(true);
}

int InpaintingParameterWidget::getSize() const
{
    return m_brushSize->value();
}

void InpaintingParameterWidget::setCircleBrushShape()
{
  this->setBrushShape(DrawableGraphicsScene::CIRCLE);
}

void InpaintingParameterWidget::setSquareBrushShape()
{
  this->setBrushShape(DrawableGraphicsScene::SQUARE);
}

void InpaintingParameterWidget::setBrushShape(DrawableGraphicsScene::BrushShape shape)
{
  m_scene->setBrushShape(shape);
}
