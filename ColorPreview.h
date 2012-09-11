#ifndef ColorPreview_H
#define ColorPreview_H

#include <QWidget>
#include <QPainter>
#include <QColor>

class ColorPreview : public QWidget
{
    Q_OBJECT

public:
    ColorPreview(QWidget* parent = 0);
    QColor color() const;
    void setColor(const QColor color);

protected:
    void paintEvent(QPaintEvent*);
    
private:
    QWidget* iParent;
    QColor iColor;
};

#endif // ColorPreview_H
