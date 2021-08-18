#include "tabnew.h"
#include "copypastecell.h"
#include "ui_tabnew.h"

TabNew::TabNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabNew)
{
    ui->setupUi(this);
}

TabNew::~TabNew()
{
    delete ui;
}

void TabNew::on_addButton_clicked()
{
//    CopyPasteCell *test = new CopyPasteCell(this);

//    test->show();
    static int i=0;
    ui->cellLayout->addWidget(new CopyPasteCell(this),i,0);
    i++;

}
