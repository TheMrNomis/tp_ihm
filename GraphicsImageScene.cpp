#include "GraphicsImageScene.h"
#include <QDebug>

GraphicsImageScene::GraphicsImageScene(QObject * parent):
  DrawableGraphicsScene(parent),
  m_pixmapItem(new QGraphicsPixmapItem)
{
  QGraphicsScene::addItem(m_pixmapItem);
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

void GraphicsImageScene::setMousePosition(const QPointF& location)
{
  qreal brushHalfSize = this->brushSize()/2.0;
  QPointF brushPosition = location - QPointF(brushHalfSize, brushHalfSize);
  this->redrawBrush(brushPosition);
}
