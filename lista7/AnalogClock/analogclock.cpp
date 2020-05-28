#include "analogclock.h"

#include <QPainter>
#include <QTime>
#include <QTimer>

AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AnalogClock::update));
    timer->start(1000);
//! [6]
    setWindowTitle(tr("zegar"));
    resize(400, 400);
    setToolTip("pomoc");
    setAutoFillBackground(true);
}
void AnalogClock::leaveEvent(QEvent *event)
{
    setBackgroundRole(QPalette::Midlight);
}
void AnalogClock::enterEvent(QEvent *event)
{
    setBackgroundRole(QPalette::Light);
}

void AnalogClock::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };
    static const QPoint secondHand[3] = {
        QPoint(7,8),
        QPoint(-7,8),
        QPoint(0,-80)
    };

    QColor hourColor(153, 204, 255);
    QColor minuteColor(255, 179, 153);
    QColor secondColor(153, 255, 204);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    painter.save();

    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    painter.setPen(hourColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
painter.setPen(Qt::NoPen);
painter.setBrush(secondColor);

painter.save();
painter.rotate(6.0 * time.second());
painter.drawConvexPolygon(secondHand,3);
painter.restore();
painter.setPen(secondColor);
}
