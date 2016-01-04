#include "GraphicsImageScene.h"
#include <QDebug>

GraphicsImageScene::GraphicsImageScene(QObject * parent):
  DrawableGraphicsScene(parent),
  m_pixmapItem(new QGraphicsPixmapItem)
{
  QGraphicsScene::addItem(m_pixmapItem);
  this->setInteractive(false);
  this->setBrushShape(CIRCLE);
  this->setBrushSize(20);
  this->setBrushVisibility(true);
}

void GraphicsImageScene::mousePressEvent(QMouseEvent *e)
{
  this->paint(e);
}

void GraphicsImageScene::mouseMoveEvent(QMouseEvent *e)
{
  if(isInteractive())
  {
      this->redrawBrush(mapToBrushCenter(e->localPos()));
      this->paint(e);
  }
}

void GraphicsImageScene::setInteractive(bool interactive)
{
  this->setBrushVisibility(interactive);
  this->setMaskVisibility(interactive);
  DrawableGraphicsScene::setInteractive(interactive);
}

QPointF GraphicsImageScene::mapToBrushCenter(QPointF const& position) const
{
  qreal brushHalfSize = this->brushSize()/2.0;
  return position - QPointF(brushHalfSize, brushHalfSize);
}

void GraphicsImageScene::paint(QMouseEvent *e)
{
  if(isInteractive())
  {
    if(e->buttons() == Qt::LeftButton)
      DrawableGraphicsScene::paint(mapToBrushCenter(e->localPos()));
    else if(e->buttons() == Qt::RightButton)
      DrawableGraphicsScene::erase(mapToBrushCenter(e->localPos()));
  }
}
