#include "ghost.h"
#include <QBrush>
#include <QPainter>
#include <QGraphicsScene>
#include <qdebug.h>

Ghost::Ghost() : QGraphicsRectItem(50, 50, 60, 60)
{

}

void Ghost::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qDebug() << scene()->collidingItems(this).isEmpty() << '\n';
    this->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
    QGraphicsRectItem::paint(painter, option, widget);
}

void Ghost::advance(int phase)
{
    static int c, t, vx, vy;

    // Let it randomly chose a direction to follow for a while
    if(c==0) {
        vx = (qrand() % 3) - 1; // ( -1, 0, 1 )
        vy = (qrand() % 3) - 1;
        t = (qrand() % 300) + 1;
        qDebug() << vx << "," << vy << " " << t;
    }

    c++;
    c %= t;

    if(phase == 1) {
        // Could be optimized, multiplication strictly not needed
        int dx = vx * ((qrand() % 2) + 1); // (1,2)
        int dy = vy * ((qrand() % 2) + 1);
        //qDebug() << "Move: " << dx << "," << dy;
        this->moveBy(dx, dy);
    }
}
