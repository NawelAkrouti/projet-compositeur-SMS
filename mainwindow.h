#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trie.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Trie* p;
    Trie* FirstNode;
    explicit MainWindow(Trie* p, Trie* FirstNode, QWidget *parent = nullptr);
    void FindWords();
    QString ch;
    size_t wordIndex;
    int lastSpaceIndex;

    ~MainWindow();

private slots:
    void Button_Clicked(QString num);
    void on_deleteBtn_clicked();
    void on_nextBtn_clicked();
    void on_spaceButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
