/**
 * @file newtabdialog.cpp
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

#include "newtabdialog.h"
#include "ui_newtabdialog.h"

NewTabDialog::NewTabDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTabDialog)
{
    ui->setupUi(this);

    qApp->installEventFilter(this);
}

NewTabDialog::~NewTabDialog()
{
    delete ui;
}

/// Filter the events
bool NewTabDialog::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::EnterWhatsThisMode) {
        _handleWhatsThisEntry(QApplication::activeWindow());
        return true;
    }
    return QObject::eventFilter(object, event);
}

/// Handle the EnterWhatsThisMode event
void NewTabDialog::_handleWhatsThisEntry(QWidget * /*sender*/) {
    qDebug() << "What's This Mode Entered";

    QMessageBox::about(this,tr("What is this?"),tr("If you want to change the name of the tab then enter new name and press 'OK', else click 'Cancel'"));
}

void NewTabDialog::setText(QString data)
{
    ui->newTabLabel->setText(data);
}

void NewTabDialog::on_okButton_clicked()
{
    QString tabName = ui->newTabText->toPlainText();
    if(tabName.isEmpty()){
        QMessageBox::warning(this,tr("Warning"),tr("Please enter valid Tab Name"));
    }
    else{
        emit newTabName(tabName);
        this->close();
    }
}

void NewTabDialog::on_cancelButton_clicked()
{
    this->close();
}
