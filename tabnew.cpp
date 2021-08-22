#include "tabnew.h"
#include "ui_tabnew.h"

TabNew::TabNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabNew)
{
    ui->setupUi(this);
    cellNumerTotal=0;
}

TabNew::~TabNew()
{
    delete ui;
}

void TabNew::addNewCell(QString cellText)
{
    CopyPasteCell *newCell = new CopyPasteCell(this);
    ui->cellLayout->addWidget(newCell,cellNumerTotal,0);
    connect(newCell,SIGNAL(closeThisCell(int)),this,SLOT(closeCell(int)));
    newCell->setAttribute(Qt::WA_DeleteOnClose,true);
    newCell->cellNumber = cellNumerTotal;
    newCell->setTextData(cellText);
    allCellPtr.append(newCell);
    cellNumerTotal++;
}

void TabNew::on_addButton_clicked()
{
    addNewCell();
}

void TabNew::closeCell(int index)
{
    allCellPtr[index]->close();
    for (int i=index+1;i<allCellPtr.length() ;i++ ) {
        allCellPtr[i]->cellNumber--;
    }
    cellNumerTotal--;
    allCellPtr.remove(index);
}
