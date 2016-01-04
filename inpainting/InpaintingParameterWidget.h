#ifndef INPAINTINGPARAMETERWIDGET_H
#define INPAINTINGPARAMETERWIDGET_H

#include "../AbstractParameterWidget.h"
#include "../DrawableGraphicsScene.h"

#include <QSpinBox>
#include <QPushButton>
#include <QButtonGroup>
#include <QGroupBox>

class InpaintingParameterWidget : public AbstractParameterWidget
{
  Q_OBJECT

public:
    InpaintingParameterWidget(DrawableGraphicsScene * scene, QWidget * parent = 0);

    int getSize() const;

private slots:
    void setCircleBrushShape();
    void setSquareBrushShape();

private:
    inline void setBrushShape(DrawableGraphicsScene::BrushShape shape);

private:
    DrawableGraphicsScene * m_scene;

    QGroupBox * m_brushGroupBox;
    QButtonGroup * m_brushButtonGroup;

    QPushButton * m_circleBrushButton;
    QPushButton * m_squareBrushButton;

    QSpinBox * m_brushSize;
};

#endif // INPAINTINGPARAMETERWIDGET_H
