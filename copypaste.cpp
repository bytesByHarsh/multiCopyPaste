#include "copypaste.h"
#include "ui_copypaste.h"


CopyPaste::CopyPaste(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CopyPaste)
{
    ui->setupUi(this);
    this->setWindowTitle("Multi Copy Paste");
    this->setWindowIcon(QIcon(":/img/img/paste.png"));
    TabNew *newTabptr=new TabNew(this);
    ui->tabWidget->addTab(newTabptr, "Default");
    newTabptr->setAttribute(Qt::WA_DeleteOnClose,true);
    allTabPtr.append(newTabptr);

}

CopyPaste::~CopyPaste()
{
    delete ui;
}


void CopyPaste::on_tabWidget_tabCloseRequested(int index)
{
    qDebug()<<"Removing tab of index:"<<index;
    ui->tabWidget->removeTab(index);

    allTabPtr.remove(index);
}


void CopyPaste::on_newTabButton_clicked()
{
    TabNew *newTabptr=new TabNew(this);

    ui->tabWidget->addTab(newTabptr, QString("Tab %0").arg(ui->tabWidget->count()+1));
    newTabptr->setAttribute(Qt::WA_DeleteOnClose,true);
    allTabPtr.append(newTabptr);
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

void CopyPaste::on_actionSave_triggered()
{

}

void CopyPaste::on_actionExit_triggered()
{
    QApplication::exit();
}
