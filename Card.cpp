#include "Card.h"

Card::Card(QWidget* parent) : QWidget(parent)
{
    iIsMousePressed = false;
    setMouseTracking(true);
    resetLogoSize();
}

void Card::create(QString filename)
{
    iOut.save(filename, 0, 100);
}

void Card::resetLogoSize()
{
    iConf.LogoX = 20;
    iConf.LogoY = 20;
}

void Card::resetMouse()
{
    iConf.MouseSize = 2;
    iMousePosition.clear();
    update();
}

void Card::paintEvent(QPaintEvent*)
{
    QPainter g(this);
    QPainter img;
    int w = size().width() - 1;
    int h = size().height() - 1;

    iOut = QPixmap(size().width(), size().height());

    img.begin(&iOut);

    QLinearGradient grad;

    // pokud ma byt gradient na pozadi horizontalne
    if (iConf.IsLeftToRight)
    {
        grad = QLinearGradient(0, 0, w, 0); // horizontal
    }
    else grad = QLinearGradient(0, 0, 0, h); // vertical

    grad.setColorAt(0, iConf.GradientA);
    grad.setColorAt(1, iConf.GradientB);
    img.setBrush(QBrush(grad));
    img.drawRect(0, 0, w, h);

    // pokud bude nastaveno vlastni logo
    if (!iConf.LogoImg.isNull())
    {
        img.drawImage(iConf.LogoX, iConf.LogoY, iConf.LogoImg);
    }
    else createLogo(img);

    // pokud se ma vykreslovat stredova cara
    if (iConf.IsLine)
    {
        img.setPen(QPen(QBrush(iConf.Line, Qt::SolidPattern), 2));
        img.drawLine(2, h / 2 + 20, w - 1, h / 2 + 20);
    }
    img.setPen(QPen(QBrush(Qt::black, Qt::SolidPattern), 1));

    img.setPen(iCompany.Color);
    img.setFont(QFont(iCompany.Font, iCompany.Size, 100));
    img.drawText(100, 40, iCompany.Text);

    img.setPen(iName.Color);
    img.setFont(QFont(iName.Font, iName.Size));
    img.drawText(100, 80, iName.Text);

    img.setPen(iPosition.Color);
    img.setFont(QFont(iPosition.Font, iPosition.Size));
    img.drawText(100, 92, iPosition.Text);

    img.setPen(iAddress.Color);
    img.setFont(QFont(iAddress.Font, iAddress.Size));
    img.drawText(20, 130, iAddress.Text);

    img.setPen(iWebsite.Color);
    img.setFont(QFont(iWebsite.Font, iWebsite.Size));
    img.drawText(20, 142, iWebsite.Text);

    img.setPen(iEmail.Color);
    img.setFont(QFont(iEmail.Font, iEmail.Size));
    img.drawText(220, 130, iEmail.Text);

    img.setPen(iMobile.Color);
    img.setFont(QFont(iMobile.Font, iMobile.Size));
    img.drawText(220, 142, iMobile.Text);

    createMouseLines(img);

    g.drawPixmap(0, 0, w, h, iOut);
}

void Card::mouseMoveEvent(QMouseEvent* e)
{
    emit MousePosition(QPoint(e->x(), e->y()));

    if (iIsMousePressed)
    {
        QVector<QPoint> v = iMousePosition.value(iActual);
        v.push_back(QPoint(e->x(), e->y()));
        iMousePosition.insert(iActual, v);
    }
}

void Card::mousePressEvent(QMouseEvent* e)
{
    iIsMousePressed = true;

    QVector<QPoint> v = iMousePosition.value(iActual);
    v.push_back(QPoint(e->x(), e->y()));
    iMousePosition.insert(iActual, v);
}

void Card::mouseReleaseEvent(QMouseEvent*)
{
    iIsMousePressed = false;
    iActual++;
}

void Card::mouseDoubleClickEvent(QMouseEvent *)
{
    iMousePosition.clear();
    iActual = 0;
    update();
}

void Card::createLogo(QPainter& g)
{
    g.setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < 2; i++)
    {
        // prvni pruchod vykresli kruhy a druhy jejich obvod
        if (!i)
        {
            g.setBrush(iConf.Logo);
        }
        else g.setPen(QPen(QBrush(iConf.LogoBorder, Qt::SolidPattern), 1));

        g.drawEllipse(20, 65, 16, 16);
        g.drawEllipse(40, 65, 16, 16);
        g.drawEllipse(60, 65, 16, 16);
        g.drawEllipse(60, 45, 16, 16);
        g.drawEllipse(40, 25, 16, 16);
    }
}

void Card::createMouseLines(QPainter& g)
{
    foreach (int key, iMousePosition.keys())
    {
        QVector<QPoint> points = iMousePosition.value(key);
        QVector<QPoint>::const_iterator it = points.begin();

        for (int i = 0; i < points.count() - 1; i++, it++)
        {
            g.setPen(QPen(QBrush(iConf.Mouse, Qt::SolidPattern), iConf.MouseSize));
            g.drawLine(*it, *(it + 1));
        }
    }
}
