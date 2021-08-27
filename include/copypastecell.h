/**
 * @file copypastecell.h
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

#ifndef COPYPASTECELL_H
#define COPYPASTECELL_H

#include <QWidget>
#include <QClipboard>
#include <QStatusBar>
#include <QString>
#include <QMessageBox>

#include "newtabdialog.h"

namespace Ui {
class CopyPasteCell;
}

class CopyPasteCell : public QWidget
{
    Q_OBJECT

public:
    explicit CopyPasteCell(QWidget *parent = nullptr);
    ~CopyPasteCell();
    int cellNumber;
    QString getTextData();
    QString getCellName();
    void setTextData(QString cellText);
    void setCellName(QString cellName);

private slots:
    void on_pasteButton_clicked();

    void on_copyButton_clicked();

    void on_clearButton_clicked();

    void on_deleteButton_clicked();

    void on_editLabelButton_clicked();

private:
    Ui::CopyPasteCell *ui;
    NewTabDialog *newWindow;

signals:
    void closeThisCell(int);
public slots:
    void recievedNewTabName(QString);
};

#endif // COPYPASTECELL_H
