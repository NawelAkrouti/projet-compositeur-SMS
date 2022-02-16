#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
Q_OBJECT
public:
    QString Nb;
    QString characters;
    Button(QString nb = "", QString c = "", QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *) override;

private slots:
    void mousePressEvent(QMouseEvent *e) override;

signals:
    void leftClicked();

};

#endif // BUTTON_H
