#ifndef INPAINTINGPARAMETERWIDGET_H
#define INPAINTINGPARAMETERWIDGET_H

#include "../AbstractParameterWidget.h"
#include "../DrawableGraphicsScene.h"

#include <QSpinBox>
#include <QSlider>
#include <QPushButton>
#include <QButtonGroup>
#include <QGroupBox>

class InpaintingParameterWidget : public AbstractParameterWidget
{
  Q_OBJECT

public:
    InpaintingParameterWidget(DrawableGraphicsScene * scene, QWidget * parent = 0);

    inline DrawableGraphicsScene::BrushShape getShape() const;
    inline int getSize() const;

private slots:
    void setCircleBrushShape();
    void setSquareBrushShape();

    void setBrushSize(int size);

private:
    inline void setBrushShape(DrawableGraphicsScene::BrushShape shape);

private:
    DrawableGraphicsScene * m_scene;

    QGroupBox * m_brushGroupBox;
    QButtonGroup * m_brushButtonGroup;

    QPushButton * m_circleBrushButton;
    QPushButton * m_squareBrushButton;

    QWidget * m_brushSizeContainerWidget;
    QSlider * m_brushSizeSlider;
    QSpinBox * m_brushSizeSpinBox;
};

#endif // INPAINTINGPARAMETERWIDGET_H
