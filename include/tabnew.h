/**
 * @file tabnew.h
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
