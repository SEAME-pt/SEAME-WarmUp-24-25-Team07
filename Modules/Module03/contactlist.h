#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "contact.h"
#include <QList>

class ContactList {
public:
    void addContact(const Contact &contact);
    void removeContact(const QString &name);
    QList<Contact> searchContacts(const QString &query) const;

    const QList<Contact>& getContacts() const;
    QList<Contact> getAllContacts();

private:
    QList<Contact> contacts;
};

#endif // CONTACTLIST_H
