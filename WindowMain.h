#ifndef WindowMain_H
#define WindowMain_H

#include <QMainWindow>
#include <QColorDialog>
#include <QMessageBox>
#include <QFontDatabase>
#include <QFileDialog>

#include "Card.h"
#include "ColorPreview.h"

namespace Ui {
    class WindowMain;
}

class WindowMain : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WindowMain(QWidget* parent = 0);
    ~WindowMain();

private slots:
    // tlacitka
    void OnClickCreate();
    void OnClickDefault();
    void OnClickSelectLogo();
    void OnClickClearLogo();

    // udalosti pri zmene textu nebo barvy
    void OnCompany(QString text);
    void OnCompanyColor();
    void OnName(QString text);
    void OnNameColor();
    void OnPosition(QString text);
    void OnPositionColor();
    void OnAddress(QString text);
    void OnAddressColor();
    void OnWebsite(QString text);
    void OnWebsiteColor();
    void OnEmail(QString text);
    void OnEmailColor();
    void OnMobile(QString text);
    void OnMobileColor();
    void OnMouseSize(QString text);
    void OnMouseColor();
    void OnGradientA();
    void OnGradientB();
    void OnLine();
    void OnLogo();
    void OnLogoBorder();

    // ostatni
    void OnIsLine();
    void OnIsLeftToRight();
    void OnLogoPosition(QString text);
    void OnMousePosition(QPoint pos);

private:
    Ui::WindowMain* ui;
    Card* iCard;

    void loadConnection();
    void loadFontsToCB();
};

#endif // WindowMain_H
