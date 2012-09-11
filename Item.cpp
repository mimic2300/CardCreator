#include "Item.h"

void Item::setColor(const QColor color)
{
    Color = color;

    if (Preview)
        Preview->setColor(color);
}
