#include "StartWindow.h"
#include <QApplication>
#include <QResource>
#include <QDirIterator>
#include <QDebug>

void printResources()
{
    QDirIterator it(":/", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qDebug() << it.next();
    }
}

int main(int argc, char* argv[])
{
    printResources();
    QApplication a(argc, argv);
    qDebug() << "\n \n \n \n";
    printResources();

    StartWindow w; 
    w.show();

    return a.exec();
}
