#include "copypaste.h"
#include "ui_copypaste.h"


CopyPaste::CopyPaste(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CopyPaste)
{
    ui->setupUi(this);
    this->setWindowTitle("Multi Copy Paste");
    this->setWindowIcon(QIcon(":/img/img/paste.png"));
    TabNew *newTabptr=new TabNew(this);
    ui->tabWidget->addTab(newTabptr, "Default");
    newTabptr->setAttribute(Qt::WA_DeleteOnClose,true);
    allTabPtr.append(newTabptr);

}

CopyPaste::~CopyPaste()
{
    delete ui;
}


void CopyPaste::on_tabWidget_tabCloseRequested(int index)
{
    qDebug()<<"Removing tab of index:"<<index;
    ui->tabWidget->removeTab(index);

    allTabPtr.remove(index);
}


void CopyPaste::on_newTabButton_clicked()
{
    TabNew *newTabptr=new TabNew(this);

    ui->tabWidget->addTab(newTabptr, QString("Tab %0").arg(ui->tabWidget->count()+1));
    newTabptr->setAttribute(Qt::WA_DeleteOnClose,true);
    allTabPtr.append(newTabptr);
}

void CopyPaste::on_tabWidget_tabBarDoubleClicked(int index)
{
//    ui->tabWidget->setTabText(index,"work");
    currDoubleClickedTab=index;
    newWindow = new NewTabDialog(this);
    connect(newWindow,SIGNAL(newTabName(QString)),this,SLOT(recievedNewTabName(QString)));
    newWindow->show();
}

void CopyPaste::recievedNewTabName(QString newName)
{
    ui->tabWidget->setTabText(currDoubleClickedTab,newName);
}

bool CopyPaste::writeAllData(QJsonObject &json){

    json["Author Name"] = "Harsh Mittal";
    json["Total Tabs"] = allTabPtr.length();

    QJsonArray tabsJSON;
    for (int i=0;i<allTabPtr.length() ;i++ ) {
        QJsonObject tabDataJSON;

        // Write data for each tab cell
        QJsonArray allCelldData;
        for (int j=0;j<allTabPtr[i]->allCellPtr.length() ;j++ ) {
            QJsonObject cellData;
            cellData["Text Data"] = allTabPtr[i]->allCellPtr[j]->getTextData();

            allCelldData.append(cellData);
        }
        tabDataJSON["Tab Name"] = ui->tabWidget->tabText(i);
        tabDataJSON["Total Cells"] = allTabPtr[i]->allCellPtr.length();
        tabDataJSON["Tab Data"] = allCelldData;
        tabsJSON.append(tabDataJSON);
    }
    json["Data"] = tabsJSON;
    return true;
}
bool CopyPaste::readAllData(const QJsonObject &json)
{
    int numTabs;
    if(json.contains("Total Tabs")){
        numTabs = json["Total Tabs"].toInt();
    }

    if(json.contains("Data") && json["Data"].isArray()){
        QJsonArray tabsJSON = json["Data"].toArray();

        for(int tabIndex=0;tabIndex<tabsJSON.size();tabIndex++){
            QJsonObject tabDataJSON = tabsJSON[tabIndex].toObject();

            // Create New Tab
            TabNew *newTabptr=new TabNew(this);

            ui->tabWidget->addTab(newTabptr, tabDataJSON["Tab Name"].toString());
            newTabptr->setAttribute(Qt::WA_DeleteOnClose,true);
            allTabPtr.append(newTabptr);

            QJsonArray allCelldData = tabDataJSON["Tab Data"].toArray();

            for (int cellIndex=0;cellIndex<allCelldData.size() ;cellIndex++ ) {
                QJsonObject cellData = allCelldData[cellIndex].toObject();
                QString cellText = cellData["Text Data"].toString();
                newTabptr->addNewCell(cellText);
//                qDebug()<<cellData;
            }


        }
    }

//    for(int i=0;i<json["Total Tabs"].toInt();i++){
//        QString tabName = json["Data"]
//    }

    return true;
}

void CopyPaste::on_actionSave_triggered()
{
//    QFile file("E:\Git\build-multiCopyPaste-Desktop_Qt_5_15_0_MinGW_64_bit-Debug\debug\test.json");
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QJsonParseError JsonParseError;
//    QJsonDocument JsonDocument = QJsonDocument::fromJson(file.readAll(), &JsonParseError);
//    file.close();

    QFile file("E:/Git/build-multiCopyPaste-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/debug/test.json");
    if(!file.open(QFile::WriteOnly)){
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonObject copyPasteObject;
    writeAllData(copyPasteObject);

    file.write(QJsonDocument(copyPasteObject).toJson());
    file.close();

    qDebug()<<"Saved File";

}

void CopyPaste::on_actionExit_triggered()
{
    QApplication::exit();
}

void CopyPaste::on_actionAbout_triggered()
{
    AboutMeDialog aboutMe;
    aboutMe.show();
    aboutMe.exec();
}

void CopyPaste::on_actionLoad_triggered()
{
    QFile file("E:/Git/build-multiCopyPaste-Desktop_Qt_5_15_0_MinGW_64_bit-Debug/debug/test.json");
    if(!file.open(QFile::ReadOnly)){
        qWarning("Couldn't open save file.");
        return;
    }

    QByteArray saveData = file.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    readAllData(loadDoc.object());

}
