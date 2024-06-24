#include<bits/stdc++.h>
#include<map>
#include <fstream>
#include <sstream>
using namespace std;
class phonebook
{ 
    private:
    map<string,long long int>directory;
    public:
     phonebook() {
        directory["Alice"] = 1234567890;
        directory["Bob"] = 9876543210;
    }
    void add_a_number(const std:: string&name,long int number)
    {
        directory[name]=number;
    }
    bool delete_a_number(const std::string&name)
    {
         return directory.erase(name);
    }
    long int search_a_number(const std:: string&name)const
    {
        auto it = directory.find(name);
        if (it != directory.end()) {
            return it->second;
        } else {
            return -1; 
        }
    }

    void displayDirectory() const {
        cout << "Phonebook Entries:" << endl;
        for (const auto& entry : directory) {
            cout << "Name: " << entry.first << ", Number: " << entry.second << endl;
        }
    }


};
int main()
{
    phonebook myPhoneBook;
    int choice;
    string name;
    int number;
    

    do {
        cout << "\nPhonebook Menu:" << endl;
        cout << "1. Add Entry" << endl;
        cout << "2. Delete Entry" << endl;
        cout << "3. Search Entry" << endl;
        cout << "4. Display Phonebook" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter number: ";
                cin >> number;
                myPhoneBook.add_a_number(name, number);
                cout << "Entry added successfully." << endl;
                break;
            case 2:
                cout << "Enter name to delete: ";
                cin >> name;
                if (myPhoneBook.delete_a_number(name)) {
                    cout << "Entry deleted successfully." << endl;
                } else {
                    cout << "Entry not found." << endl;
                }
                break;
            case 3:
                cout << "Enter name to search: ";
                cin >> name;
                number = myPhoneBook.search_a_number(name);
                if (number != -1) {
                    cout << "Number: " << number << endl;
                } else {
                    cout << "Entry not found." << endl;
                }
                break;
            case 4:
                myPhoneBook.displayDirectory();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

