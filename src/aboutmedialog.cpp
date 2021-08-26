#include "aboutmedialog.h"
#include "ui_aboutmedialog.h"

AboutMeDialog::AboutMeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutMeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Learn More about Harsh Mittal");
    this->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowIcon(QIcon(":/img/img/copy.png"));
}

AboutMeDialog::~AboutMeDialog()
{
    delete ui;
}
