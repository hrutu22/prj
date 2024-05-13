#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string name;
    int acc_no=3009;
    float balance = 4000;
public: 
    
    void new_account();
    void withdraw();
    void deposit();
    void check_balance();
    void transfer();
};

void Bank::new_account() {
    cout << "Creating a new account\n";
    cout << "Enter the name of the Depositor: ";
    cin>>name;
    cout << "Enter the initial amount to deposit: ";
    cin >> balance;
}

void Bank::withdraw() {
    float amt;
    cout << "Withdrawal\n";
    cout << "Enter the amount to withdraw: ";
    cin >> amt;
    if (amt <= 0) {
        cout << "Invalid amount\n";
    }
   else if (amt <= balance) {
        balance -= amt;
        cout << "Withdrawal successful\n";
    } else {
        cout << "Insufficient balance\n";
    }
}

void Bank::deposit() {
    float more;
    cout << "Depositing\n";
    cout << "Enter the amount to deposit: ";
    cin >> more;
    
    
   if (more <= balance) {
        balance += more;
        cout << "Deposit successful\n";
    }
    else {
        cout << "Invalid amount\n";
    }
    
 }

void Bank::check_balance() {
    cout << "Account Details:\n";
    cout << "Name of depositor: "  << endl;
    cin>>name;
    cout << "Account number: " << acc_no << endl;
    cout << "Balance: $" << balance << endl;
}

void Bank::transfer() {
    float amount;
    cout << "Transfer\n";
    cout << "Enter the amount to transfer: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount\n";
    }
    else if (amount <= balance) {
        balance -= amount;
        cout << "Transfer successful\n";
    } 
	else {
        cout << "Insufficient balance for transfer\n";
    }
}

int main() {
    string userName;
    string userPassword;
    int loginAttempt = 0;
    const int MAX_LOGIN_ATTEMPTS = 3;

  
while (loginAttempt < MAX_LOGIN_ATTEMPTS) 
    {
    	cout << "Welcome to the bank application!\n\n";	
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if ((userName == "admin" && userPassword == "admin123")) {
            cout << "Welcome to your Savings Account\n";
            break;
        } else {
            cout << "Invalid login attempt.Please try again.\n";
            loginAttempt++;
            
        }

    
       
    }

    if (loginAttempt == MAX_LOGIN_ATTEMPTS) {
        cout << "Too many login attempts! The program will now terminate.\n";
        abort();
    
    }

    Bank obj;
    int choice = 1;
    while (choice != 6) {
        cout << "\nEnter\n1. To create a new account\n2. Withdraw \n3. Deposit \n4. Check balance \n5. Transfer\n6. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                obj.new_account();
                break;
            case 2:
                obj.withdraw();
                break;
            case 3:
                obj.deposit();
                break;
            case 4:
                obj.check_balance();
                break;
            case 5:
                obj.transfer();
                break;
            case 6:
                abort();
            default:
                cout << "Illegal option\n";
        }
    }
    return 0;
}