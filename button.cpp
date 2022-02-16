#include "button.h"

#include <QMouseEvent>
#include <QPainter>

Button::Button(QString nb, QString c, QWidget *parent) : QPushButton(parent){
    Nb = nb;
    characters = c;
}

void Button::paintEvent(QPaintEvent *paint)
{
    QPushButton::paintEvent(paint);
    QPainter painter(this);
    painter.save();

    QFont font=painter.font() ;
    font.setPointSize(18);
    painter.setFont(font);

    painter.drawText(QPoint(20, 20), Nb);
    font.setPointSize(12);
    painter.setFont(font);
    painter.drawText(QPoint(40, 20), characters);

    painter.restore();
}

void Button::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton){
        emit leftClicked();
    }
}
