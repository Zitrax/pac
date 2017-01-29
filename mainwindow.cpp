#include "ghost.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUpScene();
}


void MainWindow::setUpScene()
{
    rect = new QGraphicsRectItem(0,0,10,10);
    items.push_back(rect);
    scene.addItem(rect);

    Ghost* ghost = new Ghost();
    items.push_back(ghost);
    scene.addItem(ghost);

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();
    this->setFocus();

    startTimer();
}

void MainWindow::startTimer() {
    QObject::connect(&timer, &QTimer::timeout, &scene, &QGraphicsScene::advance);
    timer.start(1000 / 33);
}

void MainWindow::keyPressEvent(QKeyEvent* ke)
{
    switch(ke->key()) {
    case Qt::Key_A:
    case Qt::Key_Left:
        rect->moveBy(-10,0);
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        rect->moveBy(10,0);
        break;
    case Qt::Key_W:
    case Qt::Key_Up:
        rect->moveBy(0,-10);
        break;
    case Qt::Key_S:
    case Qt::Key_Down:
        rect->moveBy(0,10);
        break;
    case Qt::Key_Escape:
        QApplication::quit();
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
