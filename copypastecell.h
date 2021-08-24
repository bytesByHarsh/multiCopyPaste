#ifndef COPYPASTECELL_H
#define COPYPASTECELL_H

#include <QWidget>
#include <QClipboard>
#include <QStatusBar>
#include <QString>
#include <QMessageBox>

#include "newtabdialog.h"

namespace Ui {
class CopyPasteCell;
}

class CopyPasteCell : public QWidget
{
    Q_OBJECT

public:
    explicit CopyPasteCell(QWidget *parent = nullptr);
    ~CopyPasteCell();
    int cellNumber;
    QString getTextData();
    QString getCellName();
    void setTextData(QString cellText);

private slots:
    void on_pasteButton_clicked();

    void on_copyButton_clicked();

    void on_clearButton_clicked();

    void on_deleteButton_clicked();

    void on_editLabelButton_clicked();

private:
    Ui::CopyPasteCell *ui;
    NewTabDialog *newWindow;

signals:
    void closeThisCell(int);
public slots:
    void recievedNewTabName(QString);
};

#endif // COPYPASTECELL_H
