#ifndef ADDRESSBOOKPAGE_H
#define ADDRESSBOOKPAGE_H

#include <QDialog>

namespace Ui {
    class AddressBookPage;
}
class AddressTableModel;
class OptionsModel;

QT_BEGIN_NAMESPACE
class QTableView;
class QItemSelection;
class QSortFilterProxyModel;
class QMenu;
class QModelIndex;
QT_END_NAMESPACE

/** Widget that shows a list of sending or receiving addresses.
  */
class AddressBookPage : public QDialog
{
    Q_OBJECT

public:
    enum Tabs {
        SendingTab = 0,
        ReceivingTab = 1
    };

    enum Mode {
        ForSending, /**< Open address book to pick address for sending */
        ForEditing  /**< Open address book for editing */
    };

    explicit AddressBookPage(Mode mode, Tabs tab, QWidget *parent = 0);
    ~AddressBookPage();

<<<<<<< HEAD
    void setModel(AddressTableModel *model);
=======
    void setModel(AddressTableModel *model, bool isMove);
>>>>>>> upstream/master
    void setOptionsModel(OptionsModel *optionsModel);
    const QString &getReturnValue() const { return returnValue; }

public slots:
    void done(int retval);
<<<<<<< HEAD
=======
    void exportClicked();
>>>>>>> upstream/master

private:
    Ui::AddressBookPage *ui;
    AddressTableModel *model;
    OptionsModel *optionsModel;
    Mode mode;
    Tabs tab;
    QString returnValue;
    QSortFilterProxyModel *proxyModel;
    QMenu *contextMenu;
    QAction *deleteAction; // to be able to explicitly disable it
    QString newAddressToSelect;

private slots:
    /** Delete currently selected address entry */
<<<<<<< HEAD
    void on_deleteAddress_clicked();
    /** Create a new address for receiving coins and / or add a new address book entry */
    void on_newAddress_clicked();
    /** Copy address of currently selected address entry to clipboard */
    void on_copyAddress_clicked();
=======
    void on_deleteButton_clicked();
    void on_editButton_clicked();
    /** Create a new address for receiving coins and / or add a new address book entry */
    void on_newAddressButton_clicked();
    /** Copy address of currently selected address entry to clipboard */
    void on_copyToClipboard_clicked();
>>>>>>> upstream/master
    /** Open the sign message tab in the Sign/Verify Message dialog with currently selected address */
    void on_signMessage_clicked();
    /** Open the verify message tab in the Sign/Verify Message dialog with currently selected address */
    void on_verifyMessage_clicked();
<<<<<<< HEAD
    /** Open send coins dialog for currently selected address (no button) */
    void onSendCoinsAction();
=======
>>>>>>> upstream/master
    /** Generate a QR Code from the currently selected address */
    void on_showQRCode_clicked();
    /** Copy label of currently selected address entry to clipboard (no button) */
    void onCopyLabelAction();
    /** Edit currently selected address entry (no button) */
    void onEditAction();
<<<<<<< HEAD
    /** Export button clicked */
    void on_exportButton_clicked();
=======
>>>>>>> upstream/master

    /** Set button states based on selected tab and selection */
    void selectionChanged();
    /** Spawn contextual menu (right mouse menu) for address book entry */
    void contextualMenu(const QPoint &point);
    /** New entry/entries were added to address table */
    void selectNewAddress(const QModelIndex &parent, int begin, int /*end*/);

signals:
    void signMessage(QString addr);
    void verifyMessage(QString addr);
<<<<<<< HEAD
    void sendCoins(QString addr);
=======
>>>>>>> upstream/master
};

#endif // ADDRESSBOOKPAGE_H
