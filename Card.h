#ifndef Card_H
#define Card_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

#include "Item.h"
#include "CardConfig.h"

class Card : public QWidget
{
    Q_OBJECT

public:
    Card(QWidget* parent = 0);
    void create(const QString filename);
    void resetLogoSize();
    void resetMouse();

    // reference na objekty... pres tyto objekty se meni parametry ve vizitce
    Item& company()     { return iCompany;  }
    Item& name()        { return iName;     }
    Item& position()    { return iPosition; }
    Item& address()     { return iAddress;  }
    Item& website()     { return iWebsite;  }
    Item& email()       { return iEmail;    }
    Item& mobile()      { return iMobile;   }
    CardConfig& conf()  { return iConf;     }

signals:
    void MousePosition(QPoint pos);

protected:
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);

private:
    Item iCompany, iName, iPosition, iAddress, iWebsite, iEmail, iMobile;
    CardConfig iConf;
    QPixmap iOut; // kresli se do pixmapy a z ni do layoutu

    QMap<int, QVector<QPoint> > iMousePosition;
    int iActual;
    bool iIsMousePressed;

    void createLogo(QPainter& g);
    void createMouseLines(QPainter& g);
};

#endif // Card_H
