#ifndef CardConfig_H
#define CardConfig_H

#include <QColor>

#include "ColorPreview.h"

struct CardConfig
{
    // nahledy barev pro tlacitko
    ColorPreview* GradientAPreview;
    ColorPreview* GradientBPreview;
    ColorPreview* LinePreview;
    ColorPreview* LogoPreview;
    ColorPreview* LogoBorderPreview;
    ColorPreview* MousePreview;

    // barvy, ktera se meni ve vizitce
    QColor GradientA;
    QColor GradientB;
    QColor Line; // stredova cara
    QColor Logo;
    QColor LogoBorder;

    QColor Mouse;
    int MouseSize; // sirka stetce

    QImage LogoImg; // vlastni obrazek loga

    bool IsLine; // pokud je stredova cara
    bool IsLeftToRight; // pokud ma byt gradient horizontalne

    // vlastni pozice custom loga
    int LogoX;
    int LogoY;

    //-------------------------------------

    void setGradientA(const QColor color);
    void setGradientB(const QColor color);
    void setLine(const QColor color);
    void setLogo(const QColor color);
    void setLogoBorder(const QColor color);
    void setMouse(const QColor color);
};

#endif // CardConfig_H
