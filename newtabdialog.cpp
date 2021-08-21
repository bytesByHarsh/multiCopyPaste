#include "newtabdialog.h"
#include "ui_newtabdialog.h"

NewTabDialog::NewTabDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTabDialog)
{
    ui->setupUi(this);

    qApp->installEventFilter(this);
}

NewTabDialog::~NewTabDialog()
{
    delete ui;
}

/// Filter the events
bool NewTabDialog::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::EnterWhatsThisMode) {
        _handleWhatsThisEntry(QApplication::activeWindow());
        return true;
    }
    return QObject::eventFilter(object, event);
}

/// Handle the EnterWhatsThisMode event
void NewTabDialog::_handleWhatsThisEntry(QWidget * /*sender*/) {
    qDebug() << "What's This Mode Entered";

    QMessageBox::about(this,tr("What is this?"),tr("If you want to change the name of the tab then enter new name and press 'OK', else click 'Cancel'"));
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
