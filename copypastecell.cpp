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
    emit closeThisCell(cellNumber);

//    this->close();
}
