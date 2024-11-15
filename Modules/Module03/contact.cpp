#include "contact.h"

Contact::Contact(const QString &name, const QString &phone, const QString &email)
    : name(name), phone(phone), email(email) {}

QString Contact::getName() const { return name; }
QString Contact::getPhone() const { return phone; }
QString Contact::getEmail() const { return email; }

void Contact::setName(const QString &name) { this->name = name; }
void Contact::setPhone(const QString &phone) { this->phone = phone; }
void Contact::setEmail(const QString &email) { this->email = email; }
