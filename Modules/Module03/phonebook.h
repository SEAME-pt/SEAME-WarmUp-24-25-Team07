#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QLabel>
#include <QList>
#include "contact.h"
#include "contactlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Phonebook;
}
QT_END_NAMESPACE

class Phonebook : public QMainWindow
{
    Q_OBJECT

public:
    explicit Phonebook(QWidget *parent = nullptr);
    ~Phonebook();

private slots:
    void addContact();
    void removeContact();
    void searchContacts(const QString &query);
    void updateContactList(const QList<Contact> &contacts = {});
    void clearSearchField();
    void showAllContacts();
    void clearList();

private:
    Ui::Phonebook *ui;

    QLabel *searchLabel;
    ContactList *contactList;
};
#endif // PHONEBOOK_H
