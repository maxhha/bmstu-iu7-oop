#include <QDebug>
#include <mainwindow.h>
#include <design.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  qDebug() << "Stopped at 1 floor, doors are opened.\n"
              "Waiting state...";

  for (int i = 0; i < ui->cabin_buttons.size(); ++i) {
    connect(ui->cabin_buttons[i], &QPushButton::pressed, this,
            [=, this]() {on_button_cabin_clicked(i + 1); });
  }

  for (int i = 0; i < ui->cabin_buttons.size(); ++i) {
    connect(ui->floor_buttons[i], &QPushButton::pressed, this,
            [=, this]() {on_button_floor_clicked(i + 1); });
  }

  connect(
    ui->button_Enter75kg,
    &QPushButton::pressed,
    this,
    [=, this](){ on_button_enter_clicked(75); });

  connect(
    ui->button_Enter150kg,
    &QPushButton::pressed,
    this,
    [=, this](){ on_button_enter_clicked(150); });

  connect(
    ui->button_Exit75kg,
    &QPushButton::pressed,
    this,
    [=, this](){ on_button_exit_clicked(75); });

  connect(
    ui->button_Exit150kg,
    &QPushButton::pressed,
    this,
    [=, this](){ on_button_exit_clicked(150); });
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_button_cabin_clicked(int num) {
  qDebug() << "Cabin pressed button " << num;
  lift.click(num);
}

void MainWindow::on_button_floor_clicked(int num) {
  qDebug() << "Floor " << num << " call.";
  lift.click(num);
}

void MainWindow::on_button_enter_clicked(int weight) {
    qDebug() << "Try enter " << weight << " kg mann.";
    lift.enter(weight);
}

void MainWindow::on_button_exit_clicked(int weight) {
    qDebug() << "Try exit " << weight << " kg mann.";
    lift.exit(weight);
}
