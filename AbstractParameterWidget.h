#ifndef ABSTRACTPARAMETERWIDGET_H
#define ABSTRACTPARAMETERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>

class AbstractParameterWidget : public QWidget
{
  Q_OBJECT
public:
  explicit AbstractParameterWidget(QString const& title, QWidget *parent = 0);

  inline QString title() const{return m_title;}

signals:
  void runRequest();

public slots:

protected:
  QFormLayout * m_parametersLayout;

private:
  QVBoxLayout * m_mainLayout;
  QPushButton * m_runButton;

  const QString m_title;
};

#endif // ABSTRACTPARAMETERWIDGET_H
