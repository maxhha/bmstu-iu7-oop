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

static void scene_draw_line(const void *data, const vector_t &p1, const vector_t &p2)
{
    QGraphicsScene *scene = (QGraphicsScene *) data;

    double hh = scene->height() / 2;
    double hw = scene->width() / 2;

    double x1 = p1.x;
    double y1 = p1.y;
    double x2 = p2.x;
    double y2 = p2.y;

    scene->addLine(
                x1 + hw,
                y1 + hh,
                x2 + hw,
                y2 + hh
                );
}

err_t MainWindow::draw_actions(void)
{
    QGraphicsScene *scene = ui->graphicsView->scene();

    request_t request = {
        .type = DRAW,
        .drawer = {
            .data = scene,
            .draw_line= scene_draw_line,
        }
    };

    scene->clear();

    err_t rc = request_model_manager(request);

    return rc;
}

void MainWindow::on_load_button_clicked(void)
{
    const char *name = "C:\\Users\\devma\\Projects\\oop\\lab_01\\dataOR.csv";
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
        .type = TURN,
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
