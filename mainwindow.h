#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <memory>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

protected:

    virtual void keyPressEvent(QKeyEvent* ke);

private:
    void setUpScene();
    void startTimer();

    Ui::MainWindow* ui;
    QGraphicsScene scene;
    QGraphicsRectItem* rect;

    std::vector<QGraphicsItem*> items;

    QTimer timer;
};

#endif // MAINWINDOW_H
