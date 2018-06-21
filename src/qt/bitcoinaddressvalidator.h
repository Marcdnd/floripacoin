#ifndef BITCOINADDRESSVALIDATOR_H
#define BITCOINADDRESSVALIDATOR_H

#include <QValidator>

<<<<<<< HEAD
/** Base58 entry widget validator.
   Corrects near-miss characters and refuses characters that are not part of base58.
=======
/** Base48 entry widget validator.
   Corrects near-miss characters and refuses characters that are no part of base48.
>>>>>>> upstream/master
 */
class BitcoinAddressValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinAddressValidator(QObject *parent = 0);

    State validate(QString &input, int &pos) const;

    static const int MaxAddressLength = 35;
};

#endif // BITCOINADDRESSVALIDATOR_H
