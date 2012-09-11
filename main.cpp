#include <QtGui/QApplication>
#include <QPlastiqueStyle>
#include "WindowMain.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new QPlastiqueStyle);

    WindowMain w;
    w.show();
    
    return a.exec();
}
