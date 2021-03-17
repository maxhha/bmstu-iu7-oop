#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, WIN_X, WIN_Y);
}

MainWindow::~MainWindow(void)
{
    request_t request;
    request.type = QUIT;
    request_model_manager(request);

    delete ui;
}

err_t MainWindow::draw_actions(void)
{
    QGraphicsScene *scene = ui->graphicsView->scene();

    request_t request = {
        .type = DRAW,
        .drawer = {
            .scene = scene,
        }
    };

    scene->clear();

    err_t rc = request_model_manager(request);

    return rc;
}

void MainWindow::on_load_button_clicked(void)
{
    const char *name = "..\\lab_01\\cube.txt";
    request_t request = {
        .type = LOAD,
        .file_name = name,
    };

    err_t rc = request_model_manager(request);
    if (rc != OK)
    {
        handle_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        handle_error(rc);
    }
}

void MainWindow::on_move_button_clicked(void)
{
    vector_t coeffs = {
        .x = ui->dx_box->value(),
        .y = ui->dy_box->value(),
        .z = ui->dz_box->value(),
    };

    request_t request = {
        .type = MOVE,
        .coeffs = coeffs,
    };

    err_t rc = request_model_manager(request);
    if (rc != OK)
    {
        handle_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        handle_error(rc);
    }
}

void MainWindow::on_scale_button_clicked(void)
{
    vector_t coeffs = {
        .x = ui->kx_box->value(),
        .y = ui->ky_box->value(),
        .z = ui->kz_box->value(),
    };

    request_t request = {
        .type = SCALE,
        .coeffs = coeffs,
    };

    err_t rc = request_model_manager(request);
    if (rc != OK)
    {
        handle_error(rc);
        return;
    }

    rc = draw_actions();

    if (rc != OK)
    {
        handle_error(rc);
    }
}

void MainWindow::on_turn_button_clicked(void)
{
    vector_t coeffs = {
        .x = ui->ox_box->value(),
        .y = ui->oy_box->value(),
        .z = ui->oz_box->value(),
    };

    request_t request = {
        .type = ROTATE,
        .coeffs = coeffs,
    };

    err_t rc = request_model_manager(request);

    if (rc != OK)
    {
        handle_error(rc);
        return;
    }

    rc = draw_actions();

    if (rc != OK)
    {
        handle_error(rc);
    }
}
