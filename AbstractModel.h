#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <QObject>

class AbstractModel : public QObject
{
  Q_OBJECT
public:
  explicit AbstractModel(QObject *parent = 0);

  virtual void run() = 0;

signals:
  void success();

public slots:
};

#endif // ABSTRACTMODEL_H
