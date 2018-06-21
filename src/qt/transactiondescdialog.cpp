#include "transactiondescdialog.h"
#include "ui_transactiondescdialog.h"

#include "transactiontablemodel.h"

<<<<<<< HEAD
=======
#include <QDesktopWidget>
>>>>>>> upstream/master
#include <QModelIndex>

TransactionDescDialog::TransactionDescDialog(const QModelIndex &idx, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDescDialog)
{
    ui->setupUi(this);
    QString desc = idx.data(TransactionTableModel::LongDescriptionRole).toString();
    ui->detailText->setHtml(desc);
<<<<<<< HEAD
=======

    // Center window (deleted)
//    QRect scr = QApplication::desktop()->screenGeometry();
//    move(scr.center() - rect().center());
>>>>>>> upstream/master
}

TransactionDescDialog::~TransactionDescDialog()
{
    delete ui;
}
