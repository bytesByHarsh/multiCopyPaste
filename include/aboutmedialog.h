#ifndef ABOUTMEDIALOG_H
#define ABOUTMEDIALOG_H

#include <QDialog>
#include <QIcon>

namespace Ui {
class AboutMeDialog;
}

class AboutMeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutMeDialog(QWidget *parent = nullptr);
    ~AboutMeDialog();

private:
    Ui::AboutMeDialog *ui;
};

#endif // ABOUTMEDIALOG_H
