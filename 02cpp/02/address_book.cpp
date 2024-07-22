#include <cerrno>
#include <iostream>
#include <string>
#include <vector>

struct Contact {
    std::string name;
    std::string phone;
};

class AdressBook
{
    private:
    std::vector<Contact> contacts;
    public:
    void AddContact();
    void UpdateContact();
    void SearchContact ();
    void displayMenu();
    void ListContacts();
    void DeleteContact();
    void DeleteAllContacts();
    void run();

};

void AdressBook::ListContacts() {
    if (contacts.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i + 1 << ". Name: " << contacts[i].name
                << ", Phone: " << contacts[i].phone<<"\n";
    }
}

void AdressBook::AddContact()
{
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter phone: ";
    std::cin >> newContact.phone;
    contacts.push_back(newContact);
    std::cout << "Contact added successfully.\n";

}

void AdressBook::UpdateContact()
{
    if (contacts.empty()) {
        std::cout << "No contacts to update.\n";
        return;
    }

    std::string name;
    std::cout << "Enter the name of the contact to update: ";
    std::cin >> name;
    int option=0;
    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "1-cahnge name\n";
            std::cout << "2-cahnge phone number\n";
            std::cout << "3-cahnge both\n";
            std::cin>>option;
            switch (option) {
                case 1: {
                    std::cout << "Enter new name: ";
                    std::cin >> contact.name;
                    std::cout << "Contact updated successfully.\n";
                    break;
                    }
                case 2:{
                    std::cout << "Enter new phone: ";
                    std::cin >> contact.phone;
                    std::cout << "Contact updated successfully.\n";
                    break;
                }
                case 3:
                {
                    std::cout << "Enter new name: ";
                    std::cin >> contact.name;
                    std::cout << "Enter new phone: ";
                    std::cin >> contact.phone;
                    std::cout << "Contact updated successfully.\n";
                    break;
                }
                default:
                {
                    std::cout << "unvalid option\n";
                }
            
            }
        }
        return;
    }

    std::cout << "Contact not found.\n";
}

void AdressBook::DeleteContact()
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



void AdressBook::SearchContact()
{
        if (contacts.empty()) {
        std::cout << "No contacts to search.\n";
        return;
    }

    std::string name;
    std::cout << "Enter the name to search: ";
    std::cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Name: " << contact.name
                      << ", Phone: " << contact.phone<<"\n";
            return;
        }
    }

    std::cout << "Contact not found.\n";
}


void AdressBook::DeleteAllContacts()
{
    contacts.clear();
    std::cout << "All contacts have been deleted.\n";
}


void AdressBook::displayMenu() {
    std::cout << "\nWelcome to your favorite address book!\n"
              << "What do you want to do?\n"
              << "1. List        | Lists all users\n"
              << "2. Add         | Adds a user\n"
              << "3. Delete      | Deletes a user\n"
              << "4. Delete all  | Removes all users\n"
              << "5. Search      | Search for a user\n"
              << "6. Close       | Closes the address book\n";
    }

void AdressBook::run() {
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
    AdressBook obj;
    obj.run();

    return 0;
}