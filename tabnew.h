#ifndef TABNEW_H
#define TABNEW_H

#include <QWidget>

namespace Ui {
class TabNew;
}

class TabNew : public QWidget
{
    Q_OBJECT

public:
    explicit TabNew(QWidget *parent = nullptr);
    ~TabNew();

private slots:
    void on_addButton_clicked();

private:
    Ui::TabNew *ui;
};

#endif // TABNEW_H
