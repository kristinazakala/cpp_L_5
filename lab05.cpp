#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bank_accounts {
protected:
    string surname;
    string name;
    int date_of_the_last_operation;
    int deposit_amount;

public:
    Bank_accounts(string _surname, string _name, int _date_of_the_last_operation, int _deposit_amount) : surname(_surname), name(_name), date_of_the_last_operation(_date_of_the_last_operation), deposit_amount(_deposit_amount) {}
};

class Account : public Bank_accounts {
private:
    int interest;
    int current_amount;

public:
    static vector<Account> accounts; 

    Account(string _surname, string _name, int _date_of_the_last_operation, int _deposit_amount, int _interest, int _current_amount) : Bank_accounts(_surname, _name, _date_of_the_last_operation, _deposit_amount), interest(_interest), current_amount(_current_amount) {}

    void print() {
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Date of the last operation: " << date_of_the_last_operation << endl;
        cout << "Deposit amount: " << deposit_amount << endl;
        cout << "Interest: " << interest << endl;
        cout << "Current amount: " << current_amount << endl;
    }

    static void delete_record(int recordNumber) {
        if (recordNumber >= 0 && recordNumber < accounts.size()) {
            accounts.erase(accounts.begin() + recordNumber);
            cout << "Record deleted." << endl;
        }
        else {
            cout << "Invalid record number." << endl;
        }
    }

    static void add_record(string _surname, string _name, int _date_of_the_last_operation, int _deposit_amount, int _interest, int _current_amount) {
        accounts.push_back(Account(_surname, _name, _date_of_the_last_operation, _deposit_amount, _interest, _current_amount));
        cout << "Record added." << endl;
    }
};

vector<Account> Account::accounts; 

int main() {
    int choice;
    do {
        cout << "1. Add account" << endl;
        cout << "2. Remove account" << endl;
        cout << "3. Print all accounts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter number: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string surname, name;
            int date_of_the_last_operation, deposit_amount, interest, current_amount;
            cout << "Enter surname: ";
            cin >> surname;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter date of the last operation: ";
            cin >> date_of_the_last_operation;
            cout << "Enter deposit amount: ";
            cin >> deposit_amount;
            cout << "Enter interest: ";
            cin >> interest;
            cout << "Enter current amount: ";
            cin >> current_amount;
            Account::add_record(surname, name, date_of_the_last_operation, deposit_amount, interest, current_amount); 
            break;
        }

        case 2: {
            if (!Account::accounts.empty()) {
                cout << "Enter the account number to delete: ";
                int number;
                cin >> number;
                Account::delete_record(number - 1); 
            }
            else {
                cout << "No accounts to remove." << endl;
            }
            break;
        }

        case 3: {
            if (!Account::accounts.empty()) {
                for (size_t i = 0; i < Account::accounts.size(); ++i) {
                    cout << "Account " << i + 1 << ":" << endl;
                    Account::accounts[i].print();
                    cout << endl;
                }
            }
            else {
                cout << "No accounts to print." << endl;
            }
            break;
        }

        case 4:
            cout << "Exiting" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}

