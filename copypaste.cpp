#include "copypaste.h"
#include "tabnew.h"
#include "ui_copypaste.h"


CopyPaste::CopyPaste(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CopyPaste)
{
    ui->setupUi(this);
    this->setWindowTitle("Multi Copy Paste");
    this->setWindowIcon(QIcon(":/img/img/paste.png"));
    ui->tabWidget->addTab(new TabNew(this), "Defualt");


}

CopyPaste::~CopyPaste()
{
    delete ui;
}


void CopyPaste::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}


void CopyPaste::on_newTabButton_clicked()
{
    ui->tabWidget->addTab(new TabNew(this), QString("Tab %0").arg(ui->tabWidget->count()+1));
}

void CopyPaste::on_tabWidget_tabBarDoubleClicked(int index)
{
//    ui->tabWidget->setTabText(index,"work");
    currDoubleClickedTab=index;
    newWindow = new NewTabDialog(this);
    connect(newWindow,SIGNAL(newTabName(QString)),this,SLOT(recievedNewTabName(QString)));
    newWindow->show();
}

void CopyPaste::recievedNewTabName(QString newName)
{
    ui->tabWidget->setTabText(currDoubleClickedTab,newName);
}
