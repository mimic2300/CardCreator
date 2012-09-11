#include "CardConfig.h"

void CardConfig::setGradientA(const QColor color)
{
    GradientA = color;

    if (GradientAPreview)
        GradientAPreview->setColor(color);
}

void CardConfig::setGradientB(const QColor color)
{
    GradientB = color;

    if (GradientBPreview)
        GradientBPreview->setColor(color);
}

void CardConfig::setLine(const QColor color)
{
    Line = color;

    if (LinePreview)
        LinePreview->setColor(color);
}

void CardConfig::setLogo(const QColor color)
{
    Logo = color;

    if (LogoPreview)
        LogoPreview->setColor(color);
}

void CardConfig::setLogoBorder(const QColor color)
{
    LogoBorder = color;

    if (LogoBorderPreview)
        LogoBorderPreview->setColor(color);
}

void CardConfig::setMouse(const QColor color)
{
    Mouse = color;

    if (MousePreview)
        MousePreview->setColor(color);
}
