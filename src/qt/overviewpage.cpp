#include "overviewpage.h"
#include "ui_overviewpage.h"

#include "clientmodel.h"
#include "walletmodel.h"
<<<<<<< HEAD
#include "bitcoinunits.h"
=======
#include "floripacoinunits.h"
>>>>>>> upstream/master
#include "optionsmodel.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "guiutil.h"
#include "guiconstants.h"

#include <QAbstractItemDelegate>
#include <QPainter>

#define DECORATION_SIZE 64
<<<<<<< HEAD
#define NUM_ITEMS 3
=======
#define NUM_ITEMS 20

QFont g_fontHeader;
>>>>>>> upstream/master

class TxViewDelegate : public QAbstractItemDelegate
{
    Q_OBJECT
public:
<<<<<<< HEAD
    TxViewDelegate(): QAbstractItemDelegate(), unit(BitcoinUnits::BTC)
=======
    TxViewDelegate(): QAbstractItemDelegate(), unit(FloripacoinUnits::MEC)
>>>>>>> upstream/master
    {

    }

    inline void paint(QPainter *painter, const QStyleOptionViewItem &option,
                      const QModelIndex &index ) const
    {
        painter->save();

        QIcon icon = qvariant_cast<QIcon>(index.data(Qt::DecorationRole));
        QRect mainRect = option.rect;
        QRect decorationRect(mainRect.topLeft(), QSize(DECORATION_SIZE, DECORATION_SIZE));
        int xspace = DECORATION_SIZE + 8;
        int ypad = 6;
        int halfheight = (mainRect.height() - 2*ypad)/2;
        QRect amountRect(mainRect.left() + xspace, mainRect.top()+ypad, mainRect.width() - xspace, halfheight);
        QRect addressRect(mainRect.left() + xspace, mainRect.top()+ypad+halfheight, mainRect.width() - xspace, halfheight);
        icon.paint(painter, decorationRect);

        QDateTime date = index.data(TransactionTableModel::DateRole).toDateTime();
        QString address = index.data(Qt::DisplayRole).toString();
        qint64 amount = index.data(TransactionTableModel::AmountRole).toLongLong();
        bool confirmed = index.data(TransactionTableModel::ConfirmedRole).toBool();
        QVariant value = index.data(Qt::ForegroundRole);
        QColor foreground = option.palette.color(QPalette::Text);
        if(value.canConvert<QBrush>())
        {
            QBrush brush = qvariant_cast<QBrush>(value);
            foreground = brush.color();
        }

        painter->setPen(foreground);
        painter->drawText(addressRect, Qt::AlignLeft|Qt::AlignVCenter, address);

        if(amount < 0)
        {
            foreground = COLOR_NEGATIVE;
        }
        else if(!confirmed)
        {
            foreground = COLOR_UNCONFIRMED;
        }
        else
        {
            foreground = option.palette.color(QPalette::Text);
        }
        painter->setPen(foreground);
<<<<<<< HEAD
        QString amountText = BitcoinUnits::formatWithUnit(unit, amount, true);
=======
        QString amountText = FloripacoinUnits::formatWithUnit(unit, amount, true);
>>>>>>> upstream/master
        if(!confirmed)
        {
            amountText = QString("[") + amountText + QString("]");
        }
        painter->drawText(amountRect, Qt::AlignRight|Qt::AlignVCenter, amountText);

        painter->setPen(option.palette.color(QPalette::Text));
        painter->drawText(amountRect, Qt::AlignLeft|Qt::AlignVCenter, GUIUtil::dateTimeStr(date));

        painter->restore();
    }

    inline QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return QSize(DECORATION_SIZE, DECORATION_SIZE);
    }

    int unit;

};
#include "overviewpage.moc"

OverviewPage::OverviewPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverviewPage),
    clientModel(0),
    walletModel(0),
    currentBalance(-1),
    currentUnconfirmedBalance(-1),
    currentImmatureBalance(-1),
    txdelegate(new TxViewDelegate()),
    filter(0)
{
    ui->setupUi(this);

<<<<<<< HEAD
    // Recent transactions
    ui->listTransactions->setItemDelegate(txdelegate);
    ui->listTransactions->setIconSize(QSize(DECORATION_SIZE, DECORATION_SIZE));
    ui->listTransactions->setMinimumHeight(NUM_ITEMS * (DECORATION_SIZE + 2));
    ui->listTransactions->setAttribute(Qt::WA_MacShowFocusRect, false);

    connect(ui->listTransactions, SIGNAL(clicked(QModelIndex)), this, SLOT(handleTransactionClicked(QModelIndex)));

    // init "out of sync" warning labels
    ui->labelWalletStatus->setText("(" + tr("out of sync") + ")");
    ui->labelTransactionsStatus->setText("(" + tr("out of sync") + ")");

    // start with displaying the "out of sync" warnings
    showOutOfSyncWarning(true);
=======
//    // Recent transactions
//    ui->listTransactions->setItemDelegate(txdelegate);
//    ui->listTransactions->setIconSize(QSize(DECORATION_SIZE, DECORATION_SIZE));
//    ui->listTransactions->setMinimumHeight(NUM_ITEMS * (DECORATION_SIZE + 2));
//    ui->listTransactions->setAttribute(Qt::WA_MacShowFocusRect, false);

    connect(ui->tableLastTransactionView, SIGNAL(clicked(QModelIndex)), this, SLOT(handleTransactionClicked(QModelIndex)));

//    // init "out of sync" warning labels
//    ui->labelWalletStatus->setText("(" + tr("out of sync") + ")");
//    ui->labelTransactionsStatus->setText("(" + tr("out of sync") + ")");

//    // start with displaying the "out of sync" warnings
//    showOutOfSyncWarning(true);
>>>>>>> upstream/master
}

void OverviewPage::handleTransactionClicked(const QModelIndex &index)
{
    if(filter)
        emit transactionClicked(filter->mapToSource(index));
}

OverviewPage::~OverviewPage()
{
    delete ui;
}

void OverviewPage::setBalance(qint64 balance, qint64 unconfirmedBalance, qint64 immatureBalance)
{
    int unit = walletModel->getOptionsModel()->getDisplayUnit();
    currentBalance = balance;
    currentUnconfirmedBalance = unconfirmedBalance;
    currentImmatureBalance = immatureBalance;
<<<<<<< HEAD
    ui->labelBalance->setText(BitcoinUnits::formatWithUnit(unit, balance));
    ui->labelUnconfirmed->setText(BitcoinUnits::formatWithUnit(unit, unconfirmedBalance));
    ui->labelImmature->setText(BitcoinUnits::formatWithUnit(unit, immatureBalance));

    // only show immature (newly mined) balance if it's non-zero, so as not to complicate things
    // for the non-mining users
    bool showImmature = immatureBalance != 0;
    ui->labelImmature->setVisible(showImmature);
    ui->labelImmatureText->setVisible(showImmature);
=======
    ui->labelBalance->setText(FloripacoinUnits::formatWithUnit(unit, balance));
    ui->labelUnconfirmed->setText(FloripacoinUnits::formatWithUnit(unit, unconfirmedBalance));
    ui->labelImmature->setText(FloripacoinUnits::formatWithUnit(unit, immatureBalance));

    // only show immature (newly mined) balance if it's non-zero, so as not to complicate things
    // for the non-mining users
//    bool showImmature = immatureBalance != 0;
//    ui->labelImmature->setVisible(showImmature);
//    ui->labelImmatureText->setVisible(showImmature);
}

void OverviewPage::setNumTransactions(int count)
{
//    ui->labelNumTransactions->setText(QLocale::system().toString(count));
>>>>>>> upstream/master
}

void OverviewPage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
        // Show warning if this is a prerelease version
        connect(model, SIGNAL(alertsChanged(QString)), this, SLOT(updateAlerts(QString)));
        updateAlerts(model->getStatusBarWarnings());
    }
}

void OverviewPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
    if(model && model->getOptionsModel())
    {
<<<<<<< HEAD
=======
        // Font header
        g_fontHeader = font();
        g_fontHeader.setPointSize(10);
        g_fontHeader.setBold(true);

>>>>>>> upstream/master
        // Set up transaction list
        filter = new TransactionFilterProxy();
        filter->setSourceModel(model->getTransactionTableModel());
        filter->setLimit(NUM_ITEMS);
        filter->setDynamicSortFilter(true);
        filter->setSortRole(Qt::EditRole);
        filter->sort(TransactionTableModel::Status, Qt::DescendingOrder);

<<<<<<< HEAD
        ui->listTransactions->setModel(filter);
        ui->listTransactions->setModelColumn(TransactionTableModel::ToAddress);
=======
        ui->tableLastTransactionView->setModel(filter);

        ui->tableLastTransactionView->setColumnWidth(0, 26);
        ui->tableLastTransactionView->setColumnWidth(1, 126);
        ui->tableLastTransactionView->setColumnWidth(2, 126);
        ui->tableLastTransactionView->horizontalHeader()->setStretchLastSection(false);
        ui->tableLastTransactionView->horizontalHeader()->setResizeMode(3, QHeaderView::Stretch);
        ui->tableLastTransactionView->horizontalHeader()->setResizeMode(4, QHeaderView::ResizeToContents);

//        ui->listTransactions->setModelColumn(TransactionTableModel::ToAddress);
>>>>>>> upstream/master

        // Keep up to date with wallet
        setBalance(model->getBalance(), model->getUnconfirmedBalance(), model->getImmatureBalance());
        connect(model, SIGNAL(balanceChanged(qint64, qint64, qint64)), this, SLOT(setBalance(qint64, qint64, qint64)));

        connect(model->getOptionsModel(), SIGNAL(displayUnitChanged(int)), this, SLOT(updateDisplayUnit()));
    }

<<<<<<< HEAD
    // update the display unit, to not use the default ("BTC")
=======
    // update the display unit, to not use the default ("MEC")
>>>>>>> upstream/master
    updateDisplayUnit();
}

void OverviewPage::updateDisplayUnit()
{
    if(walletModel && walletModel->getOptionsModel())
    {
        if(currentBalance != -1)
            setBalance(currentBalance, currentUnconfirmedBalance, currentImmatureBalance);

        // Update txdelegate->unit with the current unit
        txdelegate->unit = walletModel->getOptionsModel()->getDisplayUnit();

<<<<<<< HEAD
        ui->listTransactions->update();
=======
        ui->tableLastTransactionView->update();
>>>>>>> upstream/master
    }
}

void OverviewPage::updateAlerts(const QString &warnings)
{
<<<<<<< HEAD
    this->ui->labelAlerts->setVisible(!warnings.isEmpty());
    this->ui->labelAlerts->setText(warnings);
=======
//    this->ui->labelAlerts->setVisible(!warnings.isEmpty());
//    this->ui->labelAlerts->setText(warnings);
>>>>>>> upstream/master
}

void OverviewPage::showOutOfSyncWarning(bool fShow)
{
<<<<<<< HEAD
    ui->labelWalletStatus->setVisible(fShow);
    ui->labelTransactionsStatus->setVisible(fShow);
=======
//    ui->labelWalletStatus->setVisible(fShow);
//    ui->labelTransactionsStatus->setVisible(fShow);
>>>>>>> upstream/master
}
