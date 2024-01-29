#ifndef VIEW_H
#define VIEW_H

#include <string.h>

#include <QMainWindow>
#include<QDebug>

#include "ui_mainwindow.h"
#include "../controller/controller.h"
#include "graph.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class graph;
}

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  friend class graph;
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Controller controller;

 private slots:
  void operators();
  void operands();
  void equals();
  void ac();
  void x();
};

#endif  // VIEW_H
