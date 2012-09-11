#include "ColorPreview.h"

ColorPreview::ColorPreview(QWidget* parent) : QWidget(parent)
{
    iParent = parent;
}

QColor ColorPreview::color() const
{
    return iColor;
}

void ColorPreview::setColor(const QColor color)
{
    iColor = color;
    update();
}

void ColorPreview::paintEvent(QPaintEvent*)
{
    QPainter g(this);
    QSize size = iParent->size();

    g.fillRect(0, 0, size.width(), size.height(), QBrush(iColor, Qt::SolidPattern));
    g.drawRect(0, 0, size.width() - 1, size.height() - 1);
}
