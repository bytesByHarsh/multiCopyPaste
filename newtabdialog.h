#ifndef NEWTABDIALOG_H
#define NEWTABDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>

namespace Ui {
class NewTabDialog;
}

class NewTabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTabDialog(QWidget *parent = nullptr);
    ~NewTabDialog();
    bool eventFilter(QObject *object, QEvent *event);
    void _handleWhatsThisEntry(QWidget * /*sender*/);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::NewTabDialog *ui;

signals:
    void newTabName(QString);
};

#endif // NEWTABDIALOG_H
