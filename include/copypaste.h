/**
 * @file copypaste.h
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

#ifndef COPYPASTE_H
#define COPYPASTE_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include <QClipboard>
#include <QVector>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFileDialog>
#include <QDir>
#include <QUrl>
#include <QDesktopServices>

#include "newtabdialog.h"
#include "tabnew.h"
#include "aboutmedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CopyPaste; }
QT_END_NAMESPACE

class CopyPaste : public QMainWindow
{
    Q_OBJECT

public:
    CopyPaste(QWidget *parent = nullptr);
    ~CopyPaste();
    NewTabDialog *newWindow;
    QVector<TabNew *> allTabPtr;
    void addNewTab(QString tabName);
    void openJSONFile(QString fileName);


private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_newTabButton_clicked();

    void on_tabWidget_tabBarDoubleClicked(int index);

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionLoad_triggered();

    void on_actionFAQ_triggered();

    void on_actionC_triggered();

    void on_actionC_2_triggered();

    void on_actionPython_triggered();

    void on_actionJava_triggered();

    void on_actionHTML_triggered();

    void on_actionPersonel_Info_triggered();

    void on_actionDocuments_triggered();

private:
    Ui::CopyPaste *ui;
    int currDoubleClickedTab;
    bool writeAllData(QJsonObject &json);
    bool readAllData(const QJsonObject &json);

public slots:
    void recievedNewTabName(QString);
};
#endif // COPYPASTE_H
