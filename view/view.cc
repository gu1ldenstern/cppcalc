#include "view.h"

using namespace std;

// int EQUALS = 0;
// int GRAPH = 0;
//! @todo попытаться заменить все слоты на один с параметрами..
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_credit, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(operators()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_left, SIGNAL(clicked()), this, SLOT(operators()));
  connect(ui->pushButton_right, SIGNAL(clicked()), this,
          SLOT(operators()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equals()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this,
          SLOT(x()));
  connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(ac()));
  // connect(ui->pushButton_credit, SIGNAL(clicked()), this,
  //         SLOT(credit_window()));
}

MainWindow::~MainWindow() { delete ui; }


/**
 * @brief Passes operators to the controller and writes an updated expression
**/
void MainWindow::operators() {
  QPushButton *button = static_cast<QPushButton *>(sender());
  std::string new_op = button->text().toStdString();

  std::string label = controller.add_operator(new_op);

  QString new_label = QString::fromStdString(label);
  ui->label_text->setText(new_label);
}

/**
 * @brief Passes operands to the controller and writes an updated expression
**/
void MainWindow::operands() {
  QPushButton *button = static_cast<QPushButton *>(sender());
  std::string new_op = button->text().toStdString();

  std::string label = controller.add_operand(new_op);

  QString new_label = QString::fromStdString(label);
  ui->label_text->setText(new_label);
}

/**
 * @brief Passes AC message to the controller
**/
void MainWindow::ac() {
  std::string label = controller.destroy();
  QString new_label = QString::fromStdString(label);
  ui->label_text->setText(new_label);
}

/**
 * @brief Passes variable to the controller and writes an updated expression
**/
void MainWindow::x() {
  std::string label = controller.x("x");
  QString new_label = QString::fromStdString(label);
  ui->label_text->setText(new_label);
}
/**
 * @brief Responds to '-': either opens new window if we have variables, or sends message to compute the expression to the controller and writes result
**/
void MainWindow::equals() {
  if (controller.x_occured) {
    graph window(controller, this);
    window.setModal(true);
    window.exec();
  } else {
    std::string label = controller.calculate();
    QString new_label = QString::fromStdString(label);
    ui->label_text->setText(new_label);
  }
}
