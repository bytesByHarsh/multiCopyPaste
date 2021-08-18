#ifndef COPYPASTECELL_H
#define COPYPASTECELL_H

#include <QWidget>
#include <QClipboard>

namespace Ui {
class CopyPasteCell;
}

class CopyPasteCell : public QWidget
{
    Q_OBJECT

public:
    explicit CopyPasteCell(QWidget *parent = nullptr);
    ~CopyPasteCell();

private slots:
    void on_pasteButton_clicked();

    void on_copyButton_clicked();

    void on_clearButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::CopyPasteCell *ui;

};

#endif // COPYPASTECELL_H
