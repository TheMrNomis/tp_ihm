#include "InpaintingParameterWidget.h"

InpaintingParameterWidget::InpaintingParameterWidget(DrawableGraphicsScene * scene, QWidget *parent):
    AbstractParameterWidget("Inpainting",parent),
    m_scene(scene),

    m_brushGroupBox(new QGroupBox("Brush shape", this)),
    m_brushButtonGroup(new QButtonGroup()),
    m_circleBrushButton(new QPushButton("circle", m_brushGroupBox)),
    m_squareBrushButton(new QPushButton("square", m_brushGroupBox)),

    m_brushSizeContainerWidget(new QWidget(this)),
    m_brushSizeSlider(new QSlider(Qt::Horizontal, m_brushSizeContainerWidget)),
    m_brushSizeSpinBox(new QSpinBox(m_brushSizeContainerWidget))
{
  /*----brush shape----*/
  //params
  m_circleBrushButton->setCheckable(true);
  m_squareBrushButton->setCheckable(true);

  m_brushButtonGroup->setExclusive(true);

  //layouts
  m_brushButtonGroup->addButton(m_circleBrushButton);
  m_brushButtonGroup->addButton(m_squareBrushButton);

  QHBoxLayout * brushButtonsLayout = new QHBoxLayout;
  brushButtonsLayout->addWidget(m_circleBrushButton);
  brushButtonsLayout->addWidget(m_squareBrushButton);
  m_brushGroupBox->setLayout(brushButtonsLayout);

  //connects
  QObject::connect(m_circleBrushButton, SIGNAL(pressed()), this, SLOT(setCircleBrushShape()));
  QObject::connect(m_squareBrushButton, SIGNAL(pressed()), this, SLOT(setSquareBrushShape()));

  /*----brush size----*/
  //layouts
  QHBoxLayout * brushSizeContainerLayout = new QHBoxLayout;
  brushSizeContainerLayout->addWidget(m_brushSizeSlider);
  brushSizeContainerLayout->addWidget(m_brushSizeSpinBox);
  m_brushSizeContainerWidget->setLayout(brushSizeContainerLayout);

  //connects
  QObject::connect(m_brushSizeSlider, SIGNAL(valueChanged(int)), m_brushSizeSpinBox, SLOT(setValue(int)));
  QObject::connect(m_brushSizeSpinBox, SIGNAL(valueChanged(int)), m_brushSizeSlider, SLOT(setValue(int)));
  QObject::connect(m_brushSizeSlider, SIGNAL(valueChanged(int)), this, SLOT(setBrushSize(int)));

  /*----displaying----*/
  m_parametersLayout->addRow(m_brushGroupBox);
  m_parametersLayout->addRow("Size :", m_brushSizeContainerWidget);

  /*----init----*/
  m_circleBrushButton->setChecked(true);
  m_brushSizeSlider->setValue(20);
}

DrawableGraphicsScene::BrushShape InpaintingParameterWidget::getShape() const
{
  if(m_circleBrushButton->isChecked())
    return DrawableGraphicsScene::CIRCLE;
  else
    return DrawableGraphicsScene::SQUARE;
}

int InpaintingParameterWidget::getSize() const
{
    return m_brushSizeSpinBox->value();
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

void InpaintingParameterWidget::setBrushSize(int size)
{
  m_scene->setBrushSize(size);
}
