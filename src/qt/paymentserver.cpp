// Copyright (c) 2009-2012 The Bitcoin developers
<<<<<<< HEAD
=======
// Copyright (c) 2013-2079 Dr. Kimoto Chan
// Copyright (c) 2013-2018 The Floripacoin developers
>>>>>>> upstream/master
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QApplication>

#include "paymentserver.h"

#include "guiconstants.h"
#include "ui_interface.h"
#include "util.h"

#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QFileOpenEvent>
#include <QHash>
#include <QLocalServer>
#include <QLocalSocket>
#include <QStringList>
#if QT_VERSION < 0x050000
#include <QUrl>
#endif

using namespace boost;

<<<<<<< HEAD
const int BITCOIN_IPC_CONNECT_TIMEOUT = 1000; // milliseconds
const QString BITCOIN_IPC_PREFIX("floripacoin:");
=======
const int FLORIPACOIN_IPC_CONNECT_TIMEOUT = 1000; // milliseconds
const QString FLORIPACOIN_IPC_PREFIX("floripacoin:");
>>>>>>> upstream/master

//
// Create a name that is unique for:
//  testnet / non-testnet
//  data directory
//
static QString ipcServerName()
{
<<<<<<< HEAD
    QString name("BitcoinQt");
=======
    QString name("FloripacoinQt");
>>>>>>> upstream/master

    // Append a simple hash of the datadir
    // Note that GetDataDir(true) returns a different path
    // for -testnet versus main net
    QString ddir(GetDataDir(true).string().c_str());
    name.append(QString::number(qHash(ddir)));

    return name;
}

//
// This stores payment requests received before
// the main GUI window is up and ready to ask the user
// to send payment.
//
static QStringList savedPaymentRequests;

//
// Sending to the server is done synchronously, at startup.
// If the server isn't already running, startup continues,
// and the items in savedPaymentRequest will be handled
// when uiReady() is called.
//
bool PaymentServer::ipcSendCommandLine()
{
    bool fResult = false;

    const QStringList& args = qApp->arguments();
    for (int i = 1; i < args.size(); i++)
    {
<<<<<<< HEAD
        if (!args[i].startsWith(BITCOIN_IPC_PREFIX, Qt::CaseInsensitive))
=======
        if (!args[i].startsWith(FLORIPACOIN_IPC_PREFIX, Qt::CaseInsensitive))
>>>>>>> upstream/master
            continue;
        savedPaymentRequests.append(args[i]);
    }

    foreach (const QString& arg, savedPaymentRequests)
    {
        QLocalSocket* socket = new QLocalSocket();
        socket->connectToServer(ipcServerName(), QIODevice::WriteOnly);
<<<<<<< HEAD
        if (!socket->waitForConnected(BITCOIN_IPC_CONNECT_TIMEOUT))
=======
        if (!socket->waitForConnected(FLORIPACOIN_IPC_CONNECT_TIMEOUT))
>>>>>>> upstream/master
            return false;

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << arg;
        out.device()->seek(0);
        socket->write(block);
        socket->flush();

<<<<<<< HEAD
        socket->waitForBytesWritten(BITCOIN_IPC_CONNECT_TIMEOUT);
=======
        socket->waitForBytesWritten(FLORIPACOIN_IPC_CONNECT_TIMEOUT);
>>>>>>> upstream/master
        socket->disconnectFromServer();
        delete socket;
        fResult = true;
    }
    return fResult;
}

PaymentServer::PaymentServer(QApplication* parent) : QObject(parent), saveURIs(true)
{
<<<<<<< HEAD
    // Install global event filter to catch QFileOpenEvents on the mac (sent when you click bitcoin: links)
=======
    // Install global event filter to catch QFileOpenEvents on the mac (sent when you click floripacoin: links)
>>>>>>> upstream/master
    parent->installEventFilter(this);

    QString name = ipcServerName();

    // Clean up old socket leftover from a crash:
    QLocalServer::removeServer(name);

    uriServer = new QLocalServer(this);

    if (!uriServer->listen(name))
        qDebug() << tr("Cannot start floripacoin: click-to-pay handler");
    else
        connect(uriServer, SIGNAL(newConnection()), this, SLOT(handleURIConnection()));
}

bool PaymentServer::eventFilter(QObject *object, QEvent *event)
{
<<<<<<< HEAD
    // clicking on bitcoin: URLs creates FileOpen events on the Mac:
=======
    // clicking on floripacoin: URLs creates FileOpen events on the Mac:
>>>>>>> upstream/master
    if (event->type() == QEvent::FileOpen)
    {
        QFileOpenEvent* fileEvent = static_cast<QFileOpenEvent*>(event);
        if (!fileEvent->url().isEmpty())
        {
            if (saveURIs) // Before main window is ready:
                savedPaymentRequests.append(fileEvent->url().toString());
            else
                emit receivedURI(fileEvent->url().toString());
            return true;
        }
    }
    return false;
}

void PaymentServer::uiReady()
{
    saveURIs = false;
    foreach (const QString& s, savedPaymentRequests)
        emit receivedURI(s);
    savedPaymentRequests.clear();
}

void PaymentServer::handleURIConnection()
{
    QLocalSocket *clientConnection = uriServer->nextPendingConnection();

    while (clientConnection->bytesAvailable() < (int)sizeof(quint32))
        clientConnection->waitForReadyRead();

    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_4_0);
    if (clientConnection->bytesAvailable() < (int)sizeof(quint16)) {
        return;
    }
    QString message;
    in >> message;

    if (saveURIs)
        savedPaymentRequests.append(message);
    else
        emit receivedURI(message);
}
