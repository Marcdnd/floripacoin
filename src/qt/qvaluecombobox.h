#ifndef QVALUECOMBOBOX_H
#define QVALUECOMBOBOX_H

#include <QComboBox>
#include <QVariant>

/* QComboBox that can be used with QDataWidgetMapper to select ordinal values from a model. */
class QValueComboBox : public QComboBox
{
    Q_OBJECT
<<<<<<< HEAD

    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged USER true)

=======
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged USER true)
>>>>>>> upstream/master
public:
    explicit QValueComboBox(QWidget *parent = 0);

    QVariant value() const;
    void setValue(const QVariant &value);

    /** Specify model role to use as ordinal value (defaults to Qt::UserRole) */
    void setRole(int role);

signals:
    void valueChanged();

<<<<<<< HEAD
=======
public slots:

>>>>>>> upstream/master
private:
    int role;

private slots:
    void handleSelectionChanged(int idx);
};

#endif // QVALUECOMBOBOX_H
