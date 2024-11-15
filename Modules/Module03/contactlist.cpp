#include "contactlist.h"

void ContactList::addContact(const Contact &contact) {
    contacts.append(contact);
}

void ContactList::removeContact(const QString &name) {
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getName() == name) {
            contacts.removeAt(i);
            return;
        }
    }
}

QList<Contact> ContactList::searchContacts(const QString &query) const {
    QList<Contact> results;
    for (const auto &contact : contacts) {
        if (contact.getName().contains(query, Qt::CaseInsensitive) ||
            contact.getPhone().contains(query)) {
            results.append(contact);
        }
    }
    return results;
}

const QList<Contact>& ContactList::getContacts() const {
    return contacts;
}

QList<Contact> ContactList::getAllContacts() {
    return contacts;
}
