#include "GraphicsImageScene.h"
#include <QDebug>

GraphicsImageScene::GraphicsImageScene(QObject * parent):
  DrawableGraphicsScene(parent),
  m_pixmapItem(new QGraphicsPixmapItem)
{
  QGraphicsScene::addItem(m_pixmapItem);
}

/*void GraphicsImageScene::setImage(QImage const& img)
{
  m_img = img;
  m_pixmapItem->setPixmap(QPixmap::fromImage(m_img));
}

QImage GraphicsImageScene::image() const
{
  return m_img;
}
*/

void GraphicsImageScene::mousePressEvent(QMouseEvent *e)
{
    setInteractive(true);
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
}

void GraphicsImageScene::mouseReleaseEvent(QMouseEvent *e)
{
    if ( e->button() )
        setBrushVisibility(false);
}
