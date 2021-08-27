/**
 * @file tabnew.cpp
 *
 * MultiCopyPaste - a free and open-source tool to copy/paste and organize your data
 * Copyright (C) 2021 Harsh Mittal <harshmittal2210@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


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

void TabNew::addNewCell(QString cellText,QString cellName)
{
    CopyPasteCell *newCell = new CopyPasteCell(this);
    ui->cellLayout->addWidget(newCell,cellNumerTotal,0);
    connect(newCell,SIGNAL(closeThisCell(int)),this,SLOT(closeCell(int)));
    newCell->setAttribute(Qt::WA_DeleteOnClose,true);
    newCell->cellNumber = cellNumerTotal;
    newCell->setTextData(cellText);
    newCell->setCellName(cellName);
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
