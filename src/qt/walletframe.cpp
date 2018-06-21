/*
<<<<<<< HEAD
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
#include "walletframe.h"
#include "bitcoingui.h"
#include "walletstack.h"
#include "walletview.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>

WalletFrame::WalletFrame(BitcoinGUI *_gui) :
=======
 * Qt4 floripacoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 * Dr. Kimoto Chan 2013-2079
 */
#include "walletframe.h"
#include "floripacoingui.h"
#include "walletstack.h"

#include <QHBoxLayout>
#include <QMessageBox>

WalletFrame::WalletFrame(FloripacoinGUI *_gui) :
>>>>>>> upstream/master
    QFrame(_gui),
    gui(_gui),
    clientModel(0)
{
    // Leave HBox hook for adding a list view later
    QHBoxLayout *walletFrameLayout = new QHBoxLayout(this);
    setContentsMargins(0,0,0,0);
    walletStack = new WalletStack(this);
<<<<<<< HEAD
    walletStack->setBitcoinGUI(gui);
    walletFrameLayout->setContentsMargins(0,0,0,0);
    walletFrameLayout->addWidget(walletStack);

    QLabel *noWallet = new QLabel(tr("No wallet has been loaded."));
    noWallet->setAlignment(Qt::AlignCenter);
    walletStack->addWidget(noWallet);
=======
    walletStack->setFloripacoinGUI(gui);
    walletFrameLayout->setContentsMargins(0,0,0,0);
    walletFrameLayout->addWidget(walletStack);
>>>>>>> upstream/master
}

WalletFrame::~WalletFrame()
{
}

void WalletFrame::setClientModel(ClientModel *clientModel)
{
    this->clientModel = clientModel;
    walletStack->setClientModel(clientModel);
}

bool WalletFrame::addWallet(const QString& name, WalletModel *walletModel)
{
    return walletStack->addWallet(name, walletModel);
}

bool WalletFrame::setCurrentWallet(const QString& name)
{
    // TODO: Check if valid name
    walletStack->setCurrentWallet(name);
    return true;
}

void WalletFrame::removeAllWallets()
{
    walletStack->removeAllWallets();
}

bool WalletFrame::handleURI(const QString &uri)
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (!walletView)
        return false;

=======
>>>>>>> upstream/master
    return walletStack->handleURI(uri);
}

void WalletFrame::showOutOfSyncWarning(bool fShow)
{
    if (!walletStack) {
        QMessageBox box;
        box.setText("walletStack is null");
        box.exec();
        return;
    }
    walletStack->showOutOfSyncWarning(fShow);
}

void WalletFrame::gotoOverviewPage()
{
    walletStack->gotoOverviewPage();
}

void WalletFrame::gotoHistoryPage()
{
    walletStack->gotoHistoryPage();
}

void WalletFrame::gotoAddressBookPage()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletStack->gotoAddressBookPage();
=======
    walletStack->gotoAddressBookPage();
>>>>>>> upstream/master
}

void WalletFrame::gotoReceiveCoinsPage()
{
    walletStack->gotoReceiveCoinsPage();
}

void WalletFrame::gotoSendCoinsPage(QString addr)
{
    walletStack->gotoSendCoinsPage(addr);
}

void WalletFrame::gotoSignMessageTab(QString addr)
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoSignMessageTab(addr);
=======
    walletStack->gotoSignMessageTab(addr);
>>>>>>> upstream/master
}

void WalletFrame::gotoVerifyMessageTab(QString addr)
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoVerifyMessageTab(addr);
=======
    walletStack->gotoSignMessageTab(addr);
>>>>>>> upstream/master
}

void WalletFrame::encryptWallet(bool status)
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->encryptWallet(status);
=======
    walletStack->encryptWallet(status);
>>>>>>> upstream/master
}

void WalletFrame::backupWallet()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->backupWallet();
=======
    walletStack->backupWallet();
>>>>>>> upstream/master
}

void WalletFrame::changePassphrase()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->changePassphrase();
=======
    walletStack->changePassphrase();
>>>>>>> upstream/master
}

void WalletFrame::unlockWallet()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->unlockWallet();
=======
    walletStack->unlockWallet();
>>>>>>> upstream/master
}

void WalletFrame::setEncryptionStatus()
{
<<<<<<< HEAD
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletStack->setEncryptionStatus();
}

WalletView *WalletFrame::currentWalletView()
{
    return qobject_cast<WalletView*>(walletStack->currentWidget());
}

=======
    walletStack->setEncryptionStatus();
}
>>>>>>> upstream/master
