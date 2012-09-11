#ifndef Item_H
#define Item_H

#include <QString>
#include <QColor>

#include "ColorPreview.h"

struct Item
{
    QString Text;
    QString Font;
    QColor Color;
    ColorPreview* Preview; // nahled barvy (treba do tlacitka)
    int Size; // velikost fontu

    void setColor(const QColor color);
};

#endif // Item_H
