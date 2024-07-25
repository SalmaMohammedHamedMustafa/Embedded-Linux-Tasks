#include <cerrno>
#include <iostream>
#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string phone;
};

class AddressBook
{
    private:
    std::vector<Contact> contacts;
    void NameSetter(Contact& WantedContact);
    void PhoneSetter(Contact& WantedContact);
    std::string Namegetter(const Contact& WantedContact) const;
    std::string Phonegetter(const Contact& WantedContact) const;
    void AddContact();
    void UpdateContact();
    void SearchContact();
    void displayMenu();
    void ListContacts();
    void DeleteContact();
    void DeleteAllContacts();
    public:
    void run();
};

void AddressBook::NameSetter(Contact& WantedContact)
{
    std::cout << "Enter name: ";
    std::cin >> WantedContact.name;
}

void AddressBook::PhoneSetter(Contact& WantedContact)
{
    std::cout << "Enter phone: ";
    std::cin >> WantedContact.phone;
}

std::string AddressBook::Namegetter(const Contact& WantedContact) const
{
    return WantedContact.name;
}

std::string AddressBook::Phonegetter(const Contact& WantedContact) const
{
    return WantedContact.phone;
}

void AddressBook::ListContacts() {
    if (contacts.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i + 1 << ". Name: " << Namegetter(contacts[i])
                  << ", Phone: " << Phonegetter(contacts[i]) << "\n";
    }
}

void AddressBook::AddContact()
{
    Contact newContact;
    NameSetter(newContact);
    PhoneSetter(newContact);
    contacts.push_back(newContact);
    std::cout << "Contact added successfully.\n";
}

void AddressBook::UpdateContact()
{
    if (contacts.empty()) {
        std::cout << "No contacts to update.\n";
        return;
    }

    std::string name;
    std::cout << "Enter the name of the contact to update: ";
    std::cin >> name;
    int option = 0;
    bool found = false;
    for (auto& contact : contacts) {
        if (Namegetter(contact) == name) {
            found = true;
            std::cout << "1 - Change name\n";
            std::cout << "2 - Change phone number\n";
            std::cout << "3 - Change both\n";
            std::cin >> option;
            switch (option) {
                case 1:
                    NameSetter(contact);
                    std::cout << "Contact updated successfully.\n";
                    break;
                case 2:
                    PhoneSetter(contact);
                    std::cout << "Contact updated successfully.\n";
                    break;
                case 3:
                    NameSetter(contact);
                    PhoneSetter(contact);
                    std::cout << "Contact updated successfully.\n";
                    break;
                default:
                    std::cout << "Invalid option\n";
            }
            break;  // exit the loop once the contact is updated
        }
    }
    if (!found) {
        std::cout << "Contact not found.\n";
    }
}

void AddressBook::DeleteContact()
{
    if (contacts.empty()) {
        std::cout << "No contacts to delete.\n";
        return;
    }

    int index;
    std::cout << "Enter the contact number to delete: ";
    std::cin >> index;

    if (index < 1 || index > contacts.size()) {
        std::cout << "Invalid contact number.\n";
        return;
    }

    contacts.erase(contacts.begin() + index - 1);
    std::cout << "Contact deleted successfully.\n"; 
}

void AddressBook::SearchContact()
{
    if (contacts.empty()) {
        std::cout << "No contacts to search.\n";
        return;
    }

    std::string name;
    std::cout << "Enter the name to search: ";
    std::cin >> name;

    for (const auto& contact : contacts) {
        if (Namegetter(contact) == name) {
            std::cout << "Name: " << contact.name
                      << ", Phone: " << contact.phone << "\n";
            return;
        }
    }

    std::cout << "Contact not found.\n";
}

void AddressBook::DeleteAllContacts()
{
    contacts.clear();
    std::cout << "All contacts have been deleted.\n";
}

void AddressBook::displayMenu() {
    std::cout << "\nWelcome to your favorite address book!\n"
              << "What do you want to do?\n"
              << "1. List        | Lists all users\n"
              << "2. Add         | Adds a user\n"
              << "3. Delete      | Deletes a user\n"
              << "4. Delete all  | Removes all users\n"
              << "5. Search      | Search for a user\n"
              << "6. Close       | Closes the address book\n";
}

void AddressBook::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                ListContacts();
                break;
            case 2:
                AddContact();
                break;
            case 3:
                DeleteContact();
                break;
            case 4:
                DeleteAllContacts();
                break;
            case 5:
                SearchContact();
                break;
            case 6:
                std::cout << "Closing the address book.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

int main()
{
    AddressBook obj;
    obj.run();

    return 0;
}
