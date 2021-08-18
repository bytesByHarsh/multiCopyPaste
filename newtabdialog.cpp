#include "newtabdialog.h"
#include "ui_newtabdialog.h"

NewTabDialog::NewTabDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTabDialog)
{
    ui->setupUi(this);
}

NewTabDialog::~NewTabDialog()
{
    delete ui;
}

void NewTabDialog::on_okButton_clicked()
{
    QString tabName = ui->newTabText->toPlainText();
    if(tabName.isEmpty()){
        QMessageBox::warning(this,tr("Warning"),tr("Please enter valid Tab Name"));
    }
    else{
        emit newTabName(tabName);
        this->close();
    }
}

void NewTabDialog::on_cancelButton_clicked()
{
    this->close();
}
