#ifndef COPYPASTE_H
#define COPYPASTE_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include <QClipboard>
#include <QVector>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFileDialog>
#include <QDir>
#include <QUrl>
#include <QDesktopServices>

#include "newtabdialog.h"
#include "tabnew.h"
#include "aboutmedialog.h"

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
    QVector<TabNew *> allTabPtr;
    void addNewTab(QString tabName);
    void openJSONFile(QString fileName);


private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_newTabButton_clicked();

    void on_tabWidget_tabBarDoubleClicked(int index);

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionLoad_triggered();

    void on_actionFAQ_triggered();

    void on_actionC_triggered();

    void on_actionC_2_triggered();

    void on_actionPython_triggered();

    void on_actionJava_triggered();

    void on_actionHTML_triggered();

    void on_actionPersonel_Info_triggered();

    void on_actionDocuments_triggered();

private:
    Ui::CopyPaste *ui;
    int currDoubleClickedTab;
    bool writeAllData(QJsonObject &json);
    bool readAllData(const QJsonObject &json);

public slots:
    void recievedNewTabName(QString);
};
#endif // COPYPASTE_H
