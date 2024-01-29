#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>
#include <QVector>
#include "regex"

#include "view.h"
#include "ui_graph.h"

class graph : public QDialog {
  Q_OBJECT
  friend class MainWindow;
 public:
  explicit graph(Controller& controller, QWidget *parent = nullptr);
  ~graph();

 private:
  Ui::graph *ui;
  std::string lol;
  //! current number of dots that are plotted on a graph
  unsigned int STEP = 10000;
  //! reference to the controller used in MainWindow class
  Controller& cont;
  // QVector<double> x, y;
 private slots:
  void plotting();
};

#endif  // GRAPH_H
