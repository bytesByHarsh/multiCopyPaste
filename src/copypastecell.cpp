/**
 * @file copypastecell.cpp
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

#include "copypastecell.h"
#include "ui_copypastecell.h"


CopyPasteCell::CopyPasteCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CopyPasteCell)
{
    ui->setupUi(this);

    ui->pasteButton->setIcon(QIcon(":/img/img/paste.png"));
    ui->copyButton->setIcon(QIcon(":/img/img/copy.png"));
    ui->deleteButton->setIcon(QIcon(":/img/img/clear.png"));
    ui->clearButton->setIcon(QIcon(":/img/img/eraser.png"));
    ui->editLabelButton->setIcon(QIcon(":/img/img/edit.png"));

    ui->pasteButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->copyButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->deleteButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->clearButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    ui->pasteButton->setIconSize(ui->pasteButton->size());
}

CopyPasteCell::~CopyPasteCell()
{
    delete ui;
}

QString CopyPasteCell::getTextData()
{
    return ui->textEdit->toPlainText();
}

QString CopyPasteCell::getCellName()
{
    return ui->cellLabel->text();
}

void CopyPasteCell::setTextData(QString cellText)
{
    ui->textEdit->clear();
    ui->textEdit->insertPlainText(cellText);
}

void CopyPasteCell::setCellName(QString cellName)
{
    ui->cellLabel->setText(cellName);
}

void CopyPasteCell::on_pasteButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();

    if (NULL != clipboard){
        QString qstrClipText = clipboard->text();
        if (!qstrClipText.isEmpty()){
            ui->textEdit->clear();
            ui->textEdit->insertPlainText(qstrClipText);
        }
    }

}

void CopyPasteCell::on_copyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();

    QString qstrClipText = ui->textEdit->toPlainText();
    if(!qstrClipText.isEmpty()){
        clipboard->setText(qstrClipText);
    }
}

void CopyPasteCell::on_clearButton_clicked()
{
    ui->textEdit->clear();

}

void CopyPasteCell::on_deleteButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Delete This Cell?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
        emit closeThisCell(cellNumber);
    }
//    this->close();
}

void CopyPasteCell::on_editLabelButton_clicked()
{
    newWindow = new NewTabDialog(this);
    newWindow->setText("Cell Name:");
    connect(newWindow,SIGNAL(newTabName(QString)),this,SLOT(recievedNewTabName(QString)));
    newWindow->show();
}

void CopyPasteCell::recievedNewTabName(QString data)
{
    ui->cellLabel->setText(data);
}
