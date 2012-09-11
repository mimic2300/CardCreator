#include "WindowMain.h"
#include "ui_WindowMain.h"

WindowMain::WindowMain(QWidget* parent) : QMainWindow(parent), ui(new Ui::WindowMain)
{
    ui->setupUi(this);
    setFixedSize(size());

    // vytvori vizitku a vytvori nahledy barev
    iCard = new Card(this);
    iCard->company().Preview = new ColorPreview(ui->pushCompanyColor);
    iCard->name().Preview = new ColorPreview(ui->pushNameColor);
    iCard->position().Preview = new ColorPreview(ui->pushPositionColor);
    iCard->address().Preview = new ColorPreview(ui->pushAddressColor);
    iCard->website().Preview = new ColorPreview(ui->pushWebsiteColor);
    iCard->email().Preview = new ColorPreview(ui->pushEmailColor);
    iCard->mobile().Preview = new ColorPreview(ui->pushMobileColor);
    iCard->conf().GradientAPreview = new ColorPreview(ui->pushGradA);
    iCard->conf().GradientBPreview = new ColorPreview(ui->pushGradB);
    iCard->conf().LinePreview = new ColorPreview(ui->pushLineColor);
    iCard->conf().LogoPreview = new ColorPreview(ui->pushLogoColor);
    iCard->conf().LogoBorderPreview = new ColorPreview(ui->pushLogoBorderColor);
    iCard->conf().MousePreview = new ColorPreview(ui->pushMouseColor);
    ui->previewLayout->addWidget(iCard);

    loadConnection(); // nacte vsechna spojeni mezi objekty
    loadFontsToCB(); // nacte vsechny dostupne fonty do comboboxu
    OnMousePosition(QPoint(0,0)); // vychozi pozice mysi
    OnClickDefault(); // nacte vychozi nastaveni
}

WindowMain::~WindowMain()
{
    delete ui;
}

void WindowMain::OnClickCreate()
{
    iCard->create("card.png");
    QMessageBox::information(this, "Information", "Card created!");
}

void WindowMain::OnClickDefault()
{
    // nastaveni checkboxu
    ui->checkTurnLine->setChecked(true);
    ui->checkLeftToRight->setChecked(false);
    iCard->conf().IsLine = ui->checkTurnLine->isChecked();
    iCard->conf().IsLeftToRight = ui->checkLeftToRight->isChecked();

    // nastaveni textu na vizitce
    ui->lineCompany->setText("Company...");
    ui->lineName->setText("fullname");
    ui->linePosition->setText("job");
    ui->lineAddress->setText("address");
    ui->lineWebsite->setText("website");
    ui->lineEmail->setText("email");
    ui->lineMobile->setText("tel.");

    // nastaveni velikosti textu
    ui->lineCompanySize->setText("12");
    ui->lineNameSize->setText("10");
    ui->linePositionSize->setText("7");
    ui->lineAddressSize->setText("7");
    ui->lineWebsiteSize->setText("7");
    ui->lineEmailSize->setText("7");
    ui->lineMobileSize->setText("7");

    // nastaveni barev
    iCard->conf().setGradientA(Qt::white);
    iCard->conf().setGradientB(QColor::fromRgb(200,200,200));
    iCard->conf().setLogo(Qt::black);
    iCard->conf().setLogoBorder(Qt::black);
    iCard->conf().setLine(Qt::black);
    iCard->company().setColor(Qt::black);
    iCard->name().setColor(Qt::black);
    iCard->position().setColor(Qt::black);
    iCard->address().setColor(Qt::black);
    iCard->website().setColor(Qt::black);
    iCard->email().setColor(Qt::black);
    iCard->mobile().setColor(Qt::black);
    iCard->conf().setMouse(Qt::black);

    // nastaveni fontu
    int index = ui->cbCompanyFont->findText("Verdana");
    ui->cbCompanyFont->setCurrentIndex(index);
    ui->cbNameFont->setCurrentIndex(index);
    ui->cbPositionFont->setCurrentIndex(index);
    ui->cbAddressFont->setCurrentIndex(index);
    ui->cbWebsiteFont->setCurrentIndex(index);
    ui->cbEmailFont->setCurrentIndex(index);
    ui->cbMobileFont->setCurrentIndex(index);

    // nastaveni kresleni pomoci mysi
    iCard->resetMouse(); // + update
    ui->lineMouseSize->setText(QString::number(iCard->conf().MouseSize));

    OnClickClearLogo(); // nastavi vychozi logo (provadi update)
}

void WindowMain::OnClickSelectLogo()
{
    QString file = QFileDialog::getOpenFileName(this, "Select logo image", ".", "Image (*.png *.jpg *.gif)");

    if (!file.isEmpty())
    {
        iCard->conf().LogoImg = QImage(file);
        iCard->update();
    }
}

void WindowMain::OnClickClearLogo()
{
    iCard->resetLogoSize(); // nastaveni vychozi pozice loga

    // z nejakeho duvodu to musi byt v promennych, jinak nefunguje Y
    int x = iCard->conf().LogoX;
    int y = iCard->conf().LogoY;

    ui->lineLogoX->setText(QString::number(x));
    ui->lineLogoY->setText(QString::number(y));

    iCard->conf().LogoImg = QImage();
    iCard->update();
}

void WindowMain::OnCompany(QString)
{
    iCard->company().Text = ui->lineCompany->text();
    iCard->company().Size = ui->lineCompanySize->text().toInt();
    iCard->company().Font = ui->cbCompanyFont->currentText();
    iCard->update();
}

void WindowMain::OnCompanyColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->company().setColor(selected);
}

void WindowMain::OnName(QString)
{
    iCard->name().Text = ui->lineName->text();
    iCard->name().Size = ui->lineNameSize->text().toInt();
    iCard->name().Font = ui->cbNameFont->currentText();
    iCard->update();
}

void WindowMain::OnNameColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->name().setColor(selected);
}

void WindowMain::OnPosition(QString)
{
    iCard->position().Text = ui->linePosition->text();
    iCard->position().Size = ui->linePositionSize->text().toInt();
    iCard->position().Font = ui->cbPositionFont->currentText();
    iCard->update();
}

void WindowMain::OnPositionColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->position().setColor(selected);
}

void WindowMain::OnAddress(QString)
{
    iCard->address().Text = ui->lineAddress->text();
    iCard->address().Size = ui->lineAddressSize->text().toInt();
    iCard->address().Font = ui->cbAddressFont->currentText();
    iCard->update();
}

void WindowMain::OnAddressColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->address().setColor(selected);
}

void WindowMain::OnWebsite(QString)
{
    iCard->website().Text = ui->lineWebsite->text();
    iCard->website().Size = ui->lineWebsiteSize->text().toInt();
    iCard->website().Font = ui->cbWebsiteFont->currentText();
    iCard->update();
}

void WindowMain::OnWebsiteColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->website().setColor(selected);
}

void WindowMain::OnEmail(QString)
{
    iCard->email().Text = ui->lineEmail->text();
    iCard->email().Size = ui->lineEmailSize->text().toInt();
    iCard->email().Font = ui->cbEmailFont->currentText();
    iCard->update();
}

void WindowMain::OnEmailColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->email().setColor(selected);
}

void WindowMain::OnMobile(QString)
{
    iCard->mobile().Text = ui->lineMobile->text();
    iCard->mobile().Size = ui->lineMobileSize->text().toInt();
    iCard->mobile().Font = ui->cbMobileFont->currentText();
    iCard->update();
}

void WindowMain::OnMobileColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->mobile().setColor(selected);
}

void WindowMain::OnMouseSize(QString text)
{
    iCard->conf().MouseSize = text.toInt();
    iCard->update();
}

void WindowMain::OnMouseColor()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->conf().setMouse(selected);
}

void WindowMain::OnGradientA()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->conf().setGradientA(selected);
}

void WindowMain::OnGradientB()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->conf().setGradientB(selected);
}

void WindowMain::OnLine()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->conf().setLine(selected);
}

void WindowMain::OnLogo()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->conf().setLogo(selected);
}

void WindowMain::OnLogoBorder()
{
    QColor selected = QColorDialog::getColor(Qt::white, this);

    if (selected.isValid())
        iCard->conf().setLogoBorder(selected);
}

void WindowMain::OnIsLine()
{
    iCard->conf().IsLine = ui->checkTurnLine->isChecked();
    iCard->update();
}

void WindowMain::OnIsLeftToRight()
{
    iCard->conf().IsLeftToRight = ui->checkLeftToRight->isChecked();
    iCard->update();
}

void WindowMain::OnLogoPosition(QString)
{
    iCard->conf().LogoX = ui->lineLogoX->text().toInt();
    iCard->conf().LogoY = ui->lineLogoY->text().toInt();
    iCard->update();
}

void WindowMain::OnMousePosition(QPoint pos)
{
    QString axis = "[" + QString::number(pos.x()) + "," + QString::number(pos.y()) + "]";
    ui->gbPreview->setTitle("Preview: " + axis);
}

void WindowMain::loadConnection()
{
    // spoj s nazvem spolecnosti
    connect(ui->lineCompany, SIGNAL(textChanged(QString)), this, SLOT(OnCompany(QString)));
    connect(ui->lineCompanySize, SIGNAL(textChanged(QString)), this, SLOT(OnCompany(QString)));
    connect(ui->cbCompanyFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(OnCompany(QString)));
    connect(ui->pushCompanyColor, SIGNAL(clicked()), this, SLOT(OnCompanyColor()));

    // spoj se jmenem
    connect(ui->lineName, SIGNAL(textChanged(QString)), this, SLOT(OnName(QString)));
    connect(ui->lineNameSize, SIGNAL(textChanged(QString)), this, SLOT(OnName(QString)));
    connect(ui->cbNameFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(OnName(QString)));
    connect(ui->pushNameColor, SIGNAL(clicked()), this, SLOT(OnNameColor()));

    // spoj s pozici
    connect(ui->linePosition, SIGNAL(textChanged(QString)), this, SLOT(OnPosition(QString)));
    connect(ui->linePositionSize, SIGNAL(textChanged(QString)), this, SLOT(OnPosition(QString)));
    connect(ui->cbPositionFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(OnPosition(QString)));
    connect(ui->pushPositionColor, SIGNAL(clicked()), this, SLOT(OnPositionColor()));

    // spoj s adresou
    connect(ui->lineAddress, SIGNAL(textChanged(QString)), this, SLOT(OnAddress(QString)));
    connect(ui->lineAddressSize, SIGNAL(textChanged(QString)), this, SLOT(OnAddress(QString)));
    connect(ui->cbAddressFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(OnAddress(QString)));
    connect(ui->pushAddressColor, SIGNAL(clicked()), this, SLOT(OnAddressColor()));

    // spoj se strankou
    connect(ui->lineWebsite, SIGNAL(textChanged(QString)), this, SLOT(OnWebsite(QString)));
    connect(ui->lineWebsiteSize, SIGNAL(textChanged(QString)), this, SLOT(OnWebsite(QString)));
    connect(ui->cbWebsiteFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(OnWebsite(QString)));
    connect(ui->pushWebsiteColor, SIGNAL(clicked()), this, SLOT(OnWebsiteColor()));

    // spoj s emailem
    connect(ui->lineEmail, SIGNAL(textChanged(QString)), this, SLOT(OnEmail(QString)));
    connect(ui->lineEmailSize, SIGNAL(textChanged(QString)), this, SLOT(OnEmail(QString)));
    connect(ui->cbEmailFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(OnEmail(QString)));
    connect(ui->pushEmailColor, SIGNAL(clicked()), this, SLOT(OnEmailColor()));

    // spoj s mobilem
    connect(ui->lineMobile, SIGNAL(textChanged(QString)), this, SLOT(OnMobile(QString)));
    connect(ui->lineMobileSize, SIGNAL(textChanged(QString)), this, SLOT(OnMobile(QString)));
    connect(ui->cbMobileFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(OnMobile(QString)));
    connect(ui->pushMobileColor, SIGNAL(clicked()), this, SLOT(OnMobileColor()));

    // spoj s gradientem, ktery je na pozadi vizitky
    connect(ui->pushGradA, SIGNAL(clicked()), this, SLOT(OnGradientA()));
    connect(ui->pushGradB, SIGNAL(clicked()), this, SLOT(OnGradientB()));
    connect(ui->checkLeftToRight, SIGNAL(clicked()), this, SLOT(OnIsLeftToRight()));

    // spoj se stredovou carou na vizitce
    connect(ui->checkTurnLine, SIGNAL(clicked()), this, SLOT(OnIsLine()));
    connect(ui->pushLineColor, SIGNAL(clicked()), this, SLOT(OnLine()));

    // spoj s logem
    connect(ui->pushLogoColor, SIGNAL(clicked()), this, SLOT(OnLogo()));
    connect(ui->pushLogoBorderColor, SIGNAL(clicked()), this, SLOT(OnLogoBorder()));
    connect(ui->lineLogoX, SIGNAL(textChanged(QString)), this, SLOT(OnLogoPosition(QString)));
    connect(ui->lineLogoY, SIGNAL(textChanged(QString)), this, SLOT(OnLogoPosition(QString)));

    // spoj pro malovani mysi
    connect(ui->pushMouseColor, SIGNAL(clicked()), this, SLOT(OnMouseColor()));
    connect(ui->lineMouseSize, SIGNAL(textChanged(QString)), this, SLOT(OnMouseSize(QString)));

    // spoj s tlacitky
    connect(ui->pushCreate, SIGNAL(clicked()), this, SLOT(OnClickCreate()));
    connect(ui->pushDefault, SIGNAL(clicked()), this, SLOT(OnClickDefault()));
    connect(ui->pushSelectLogo, SIGNAL(clicked()), this, SLOT(OnClickSelectLogo()));
    connect(ui->pushClearLogo, SIGNAL(clicked()), this, SLOT(OnClickClearLogo()));

    // ostatni spoje
    connect(iCard, SIGNAL(MousePosition(QPoint)), this, SLOT(OnMousePosition(QPoint)));
}

void WindowMain::loadFontsToCB()
{
    QFontDatabase fd;
    QStringList fonst = fd.families();

    ui->cbCompanyFont->addItems(fonst);
    ui->cbNameFont->addItems(fonst);
    ui->cbPositionFont->addItems(fonst);
    ui->cbAddressFont->addItems(fonst);
    ui->cbWebsiteFont->addItems(fonst);
    ui->cbEmailFont->addItems(fonst);
    ui->cbMobileFont->addItems(fonst);
}
