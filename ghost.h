#pragma once

#include <QGraphicsRectItem>

class Ghost : public QGraphicsRectItem {
public:
    Ghost();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
public slots:
    void advance(int phase) override;
};

