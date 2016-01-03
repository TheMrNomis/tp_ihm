#include "GraphicsImageScene.h"

GraphicsImageScene::GraphicsImageScene(QObject * parent):
  QGraphicsScene(parent),
  m_pixmapItem(new QGraphicsPixmapItem)
{
  QGraphicsScene::addItem(m_pixmapItem);
}

void GraphicsImageScene::setImage(QImage const& img)
{
  m_img = img;
  m_pixmapItem->setPixmap(QPixmap::fromImage(m_img));
}

QImage GraphicsImageScene::image() const
{
  return m_img;
}
