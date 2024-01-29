#include "graph.h"

graph::graph(Controller& controller, QWidget *parent)
    : QDialog(parent), ui(new Ui::graph), cont(controller) {
  ui->setupUi(this);
  connect(ui->replotting, SIGNAL(clicked()), this, SLOT(plotting()));
}

graph::~graph() {
  delete ui;
  cont.x_occured = false;
  cont.destroy();
}


/**
 * @brief Plots graph and shows calculated y value
 *
 * @details This function has two objectives: to plot the graph and to calculate y value
 * 1. Calculation:
 *    - Check if inputed x value is valid, otherwise shows error message
 *    - Shows y value passed from controller
 * 2. Plotting:
 *    - Checks limits for correctness, shows 2 types of errors: if limits can not be
 * casted as numbers or if lower limit exceeds higher
 *    - Turnes strings of limits to doubles
 *    - Gets X and Y vectors from controller, turnes them to QVectors
 *    - Sets limits to the graph and plots it
**/
void graph::plotting() {
  QRegularExpression re("^[-]?[0-9]+([.][0-9]+)?$");
  if (!(re.match(ui->inputx->text()).hasMatch())) {
    ui->result->setText("that's not a number");
  } else {
    double x_single = ui->inputx->text().toDouble();
    std::string label = cont.calculate(x_single);
    QString new_label = QString::fromStdString(label);
    ui->result->setText(new_label);
  }

  if (!((re.match(ui->xmin->text()).hasMatch()) &&
      (re.match(ui->xmax->text()).hasMatch()) &&
      (re.match(ui->ymin->text()).hasMatch()) &&
      (re.match(ui->ymax->text()).hasMatch()))) {
    ui->errors->setText(
    QString::fromStdString("ERROR: limits should\n be numbers"));
    return;
  }
  double x_min = ui->xmin->text().toDouble();
  double x_max = ui->xmax->text().toDouble();
  double y_min = ui->ymin->text().toDouble();
  double y_max = ui->ymax->text().toDouble();
  if (!((x_min < x_max) && (y_min < y_max))) {
    ui->errors->setText(
    QString::fromStdString("ERROR: min should\n not exceed max"));
    return;
  }
  ui->errors->setText(
  QString::fromStdString(cont.get_view_expression()));
  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->yAxis->setRange(y_min, y_max);
  std::vector<double> xstd;
  std::vector<double> ystd;
  cont.fill_vectors(x_min, x_max, xstd, ystd, STEP);
  QVector<double> x  = QVector<double>(xstd.begin(), xstd.end());
  QVector<double> y  = QVector<double>(ystd.begin(), ystd.end());
  ui->widget->addGraph();
  QPen pen;
  pen.setWidth(1);
  pen.setColor(QColor(122, 10, 10));
  ui->widget->graph(0)->setPen(pen);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setAdaptiveSampling(false);
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}