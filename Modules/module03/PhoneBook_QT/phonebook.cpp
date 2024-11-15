#include "phonebook.h"
#include "./ui_phonebook.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIntValidator>
#include "contact.h"
#include "contactlist.h"

Phonebook::Phonebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Phonebook)
    , contactList(new ContactList)
{
    ui->setupUi(this);

    // ui->searchLabel->setAlignment(Qt::AlignCenter);
    ui->searchLabel->setBuddy(ui->searchLineEdit); // link label to input search

    ui->searchLineEdit->setPlaceholderText("Name or phonenumber");
    ui->searchLineEdit->setMaxLength(20);

    QPushButton *addContactButton = new QPushButton("Adicionar Contato", this);

    QLabel *nameLabel = new QLabel("Name:", this);
    QLineEdit *nameLineEdit = new QLineEdit(this);
    QLabel *phoneLabel = new QLabel("Phonenumber:", this);
    QLineEdit *phoneLineEdit = new QLineEdit(this);


    ui->appNameLabel->setWordWrap(true);  // word-wrap
    ui->appNameLabel->setStyleSheet(
        "color: rgb(0, 128, 255);"        // blue color
        "font-size: 24px;"                // font size
        "font-weight: bold;"              // Bold
        "font-family: Arial, Helvetica;"  // font type
        );

    QIntValidator *validator = new QIntValidator(0, 999999999, this);  // only numbers
    ui->phoneLineEdit->setValidator(validator);

    ui->nameLineEdit->setMaxLength(20);  // max 20 chars
    ui->phoneLineEdit->setMaxLength(10); // max 9 chars
    // Layout para o formulário
    QVBoxLayout *formLayout = new QVBoxLayout;
    formLayout->addWidget(nameLabel);
    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(phoneLabel);
    formLayout->addWidget(phoneLineEdit);
    formLayout->addWidget(addContactButton);


    // Adicione o layout ao widget central
    QWidget *formWidget = new QWidget(this);
    formWidget->setLayout(formLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(ui->searchLabel);       // search label
    mainLayout->addWidget(ui->searchLineEdit);    // search input
    mainLayout->addWidget(formWidget);            // search form

    // QWidget *centralWidget = new QWidget(this);
    // centralWidget->setLayout(mainLayout);
    // setCentralWidget(centralWidget);
    connect(ui->searchLineEdit, &QLineEdit::returnPressed, this, &Phonebook::clearSearchField); // clean input after press return

    connect(ui->addContactButton, &QPushButton::clicked, this, &Phonebook::addContact);
    connect(ui->eraseButton, &QPushButton::clicked, this, &Phonebook::removeContact);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &Phonebook::searchContacts);
    connect(ui->showAllContactsButton, &QPushButton::clicked, this, &Phonebook::showAllContacts);
    connect(ui->clearListButton, &QPushButton::clicked, this, &Phonebook::clearList);
}

Phonebook::~Phonebook()
{
    delete ui;
    delete contactList;
}


void Phonebook::addContact() {
    QString name = ui->nameLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    contactList->addContact(Contact(name, phone));

    ui->nameLineEdit->clear();
    ui->phoneLineEdit->clear();

    updateContactList();
}

void Phonebook::removeContact() {
    // QString name = ui->nameLineEdit->text();
    // contactList->removeContact(name);
    // updateContactList();
    QListWidgetItem *selectedItem = ui->contactListWidget->currentItem();

    if (selectedItem) {

        QString contactName = selectedItem->text().split(" - ").first();
        contactList->removeContact(contactName);
        delete selectedItem;
        updateContactList();
        ui->searchLineEdit->clear();
    } else {
        qDebug() << "Nenhum item selecionado!";
    }
}

void Phonebook::searchContacts(const QString &query) {
    auto results = contactList->searchContacts(query);
    updateContactList(results);
}

void Phonebook::clearSearchField() {
    ui->searchLineEdit->clear();
}


void Phonebook::updateContactList(const QList<Contact> &contacts) {
    ui->contactListWidget->clear();
    for (const auto &contact : contacts) {
        ui->contactListWidget->addItem(contact.getName() + " - " + contact.getPhone());
    }
}

void Phonebook::showAllContacts() {
    // Chama a função de atualizar a lista com todos os contatos
    updateContactList(contactList->getAllContacts());
}

void Phonebook::clearList() {
    ui->contactListWidget->clear();  // clean the QListWidget
}
