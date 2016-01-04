#include "GraphicsImageScene.h"
#include <QDebug>

GraphicsImageScene::GraphicsImageScene(QObject * parent):
  DrawableGraphicsScene(parent),
  m_pixmapItem(new QGraphicsPixmapItem)
{
  QGraphicsScene::addItem(m_pixmapItem);
  this->setInteractive(true);
  this->setBrushShape(CIRCLE);
  this->setBrushSize(20);
  this->setBrushVisibility(true);
}

void GraphicsImageScene::mousePressEvent(QMouseEvent *e)
{
    /*setInteractive(true);
    setBrushVisibility(true);

    mask();
    //redrawBrush(e->localPos());
    if ( isInteractive() == true){

        if ( e->button() == Qt::LeftButton ){
            paint(e->localPos());
            qDebug() << "clic gauche";
        }
        else if( e->button() == Qt::RightButton ){
            erase(e->localPos());
        }

        //redrawBrush(e->localPos());
    }
    */
}

void GraphicsImageScene::mouseReleaseEvent(QMouseEvent *e)
{
    /*if ( e->button() )
        setBrushVisibility(false);
        */
}

void GraphicsImageScene::mouseMoveEvent(QMouseEvent *e)
{
  this->redrawBrush(mapToBrushCenter(e->localPos()));
}

QPointF GraphicsImageScene::mapToBrushCenter(QPointF const& position) const
{
  qreal brushHalfSize = this->brushSize()/2.0;
  return position - QPointF(brushHalfSize, brushHalfSize);
}
