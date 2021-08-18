#ifndef COPYPASTE_H
#define COPYPASTE_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include <QClipboard>

#include "newtabdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CopyPaste; }
QT_END_NAMESPACE

class CopyPaste : public QMainWindow
{
    Q_OBJECT

public:
    CopyPaste(QWidget *parent = nullptr);
    ~CopyPaste();
    NewTabDialog *newWindow;


private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_newTabButton_clicked();

    void on_tabWidget_tabBarDoubleClicked(int index);

private:
    Ui::CopyPaste *ui;
    int currDoubleClickedTab;

public slots:
    void recievedNewTabName(QString);
};
#endif // COPYPASTE_H
