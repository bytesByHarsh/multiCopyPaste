#ifndef COPYPASTECELL_H
#define COPYPASTECELL_H

#include <QWidget>
#include <QClipboard>
#include <QStatusBar>
#include <QString>
#include <QMessageBox>

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
    void setTextData(QString cellText);

private slots:
    void on_pasteButton_clicked();

    void on_copyButton_clicked();

    void on_clearButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::CopyPasteCell *ui;

signals:
    void closeThisCell(int);

};

#endif // COPYPASTECELL_H
