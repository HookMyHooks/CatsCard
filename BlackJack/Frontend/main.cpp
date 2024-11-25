#include "FrontEnd.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    FrontEnd w; // FrontEnd handles its own initialization
    w.show();

    return a.exec();
}
