#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <iostream>
#include "button.h"
#include <fstream>

MainWindow::MainWindow(Trie* p, Trie* FirstNode, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->p = p;
    this->FirstNode= FirstNode;
    this->ch = "";

    ui->setupUi(this);
    ui->wordsEdit->setReadOnly(true);


    Button* buttons[9] = {
        new Button("1", ""),
        new Button("2", "abc"),
        new Button("3", "def"),
        new Button("4", "ghi"),
        new Button("5", "jkl"),
        new Button("6", "mno"),
        new Button("7", "pqrs"),
        new Button("8", "tuv"),
        new Button("9", "wxyz"),
    };

    int k = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            ui->gridLayout->addWidget(buttons[k++], i, j);
        }
    }

    QSignalMapper* signalMapper = new QSignalMapper (this);
    for(Button* b : buttons){
        connect (b, SIGNAL(leftClicked()), signalMapper, SLOT(map()));
        signalMapper -> setMapping (b, b->Nb);
    }

    connect (signalMapper, SIGNAL( mappedString(QString)), this, SLOT(Button_Clicked(QString))) ;
}

void MainWindow::Button_Clicked(QString num)
{
    ch += num;
    FindWords();

}

void MainWindow::FindWords(){
    QString data = ch;
    std::vector<std::string> words = p->Find(data.toStdString(), FirstNode);

    QString p_word;
    if(!words.empty()){
        p_word = QString::fromStdString(words.at(0));
    }
    else{
        p_word = ui->wordsEdit->toPlainText() + ch.right(1);
    }
    ui->wordsEdit->setText(p_word);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deleteBtn_clicked()
{
    if(ch.length() >= 0){
        ch.chop(1);
        FindWords();
    }
}

void MainWindow::on_nextBtn_clicked()
{
    QString data = ch;
    std::vector<std::string> words = p->Find(data.toStdString(), FirstNode);

    if(words.size() > 0){
        wordIndex++;
        wordIndex %= words.size();

        QString p_word;
        if(!words.empty()){
            p_word = QString::fromStdString(words.at(wordIndex));
        }
        else{
            p_word = ui->wordsEdit->toPlainText();
        }
        ui->wordsEdit->setText(p_word);
    }
}

void MainWindow::on_spaceButton_clicked()
{
    ui->finalText->setText(ui->finalText->toPlainText() + " " + ui->wordsEdit->toPlainText());
    ui->wordsEdit->setText("");
    ch = "";
}
