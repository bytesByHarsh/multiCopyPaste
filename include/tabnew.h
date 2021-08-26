#ifndef TABNEW_H
#define TABNEW_H

#include <QWidget>
#include <QVector>

#include "copypastecell.h"

namespace Ui {
class TabNew;
}

class TabNew : public QWidget
{
    Q_OBJECT

public:
    explicit TabNew(QWidget *parent = nullptr);
    ~TabNew();
    QVector<CopyPasteCell *> allCellPtr;
    int cellNumerTotal;
    void addNewCell(QString cellText="",QString cellName="Cell Name");

private slots:
    void on_addButton_clicked();

private:
    Ui::TabNew *ui;

public slots:
    void closeCell(int);
};

#endif // TABNEW_H
