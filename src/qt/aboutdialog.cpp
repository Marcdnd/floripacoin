#include "aboutdialog.h"
#include "ui_aboutdialog.h"

<<<<<<< HEAD
#include "clientmodel.h"
#include "clientversion.h"

// Copyright year (2009-this)
// Todo: update this when changing our copyright comments in the source
const int ABOUTDIALOG_COPYRIGHT_YEAR = 2013;
=======
#include <QDesktopWidget>

#include "clientmodel.h"
#include "dialog_move_handler.h"

// Copyright year (2009-this)
// Todo: update this when changing our copyright comments in the source
const int ABOUTDIALOG_COPYRIGHT_YEAR = 2018;
>>>>>>> upstream/master

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
<<<<<<< HEAD

    // Set current copyright year
    ui->copyrightLabel->setText(tr("Copyright") + QString(" &copy; 2009-%1 ").arg(COPYRIGHT_YEAR) + tr("The Bitcoin developers") + QString("<br>") + tr("Copyright") + QString(" &copy; ") + tr("2011-%1 The Floripacoin developers").arg(ABOUTDIALOG_COPYRIGHT_YEAR));
=======
    setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::Window);
    ui->wCaption->installEventFilter(new DialogMoveHandler(this));
    // Set current copyright year
    ui->copyrightLabel->setText(tr("Copyright") + QString(" &copy; 2013-%1 ").arg("2018") + tr("The Floripacoin developers"));

    // Center window (deleted)
//    QRect scr = QApplication::desktop()->screenGeometry();
//    move(scr.center() - rect().center());
>>>>>>> upstream/master
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
