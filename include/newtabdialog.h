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

#ifndef NEWTABDIALOG_H
#define NEWTABDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>

namespace Ui {
class NewTabDialog;
}

class NewTabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTabDialog(QWidget *parent = nullptr);
    ~NewTabDialog();
    bool eventFilter(QObject *object, QEvent *event);
    void _handleWhatsThisEntry(QWidget * /*sender*/);
    void setText(QString data);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::NewTabDialog *ui;

signals:
    void newTabName(QString);
};

#endif // NEWTABDIALOG_H
