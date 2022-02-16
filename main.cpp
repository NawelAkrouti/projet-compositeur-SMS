
#include "mainwindow.h"
#include "trie.h"

#include <QApplication>
#include <QObject>
#include <fstream>


 int main(int argc, char *argv[])
{
    Trie* p = new Trie();
    Trie* FirstNode = p->NewNode();

    std::ifstream input;
    input.open("C:/Users/LENOVO/Documents/dictionary.txt");
    std::string ch;
    if(input.is_open()){
        while(getline(input, ch)){
            p->AddWord(ch, FirstNode);

        }

    }

    input.close();

    QApplication a(argc, argv);
    MainWindow w(p, FirstNode);
    w.show();

    return a.exec();
}
