/*Define a class to represent a bank account. Include the following members.
Data members
a)Account number
b) Balance amount in the account.
Member functions.
a) To assign initial values
b) To display account number and balance.
c) void moneyTransfer( ….) To transfer amount from one account from one account to other .
Minimum balance of account is Rs 1000, Before money transfer check, it shouldn&#39;t be less than
minimum balance. Write a program to test successful transfer of money from one account to other
and display appropriate account balance of both account.*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber; // Account number
    double balance;    // Balance amount in the account

public:
    // Function to assign initial values
    void assignInitialValues(int accNum, double bal) {
        accountNumber = accNum;
        balance = bal;
    }

    // Function to display account number and balance
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs " << balance << endl;
    }

    // Function to transfer money from one account to another
    void moneyTransfer(BankAccount &toAccount, double amount) {
        const double MIN_BALANCE = 1000.0; // Minimum balance requirement

        // Check if the sender has sufficient balance
        if (balance - amount < MIN_BALANCE) {
            cout << "Transfer failed! Insufficient balance in Account " << accountNumber << "." << endl;
            cout << "Minimum balance of Rs " << MIN_BALANCE << " must be maintained." << endl;
            return;
        }

        // Perform the transfer
        balance -= amount;       // Deduct amount from sender's account
        toAccount.balance += amount; // Add amount to receiver's account

        cout << "Transfer successful!" << endl;
        cout << "Rs " << amount << " transferred from Account " << accountNumber
             << " to Account " << toAccount.accountNumber << "." << endl;
    }
};

int main() {
    // Create two bank accounts
    BankAccount account1, account2;

    // Assign initial values to the accounts
    account1.assignInitialValues(1001, 5000.0); // Account 1 with Rs 5000
    account2.assignInitialValues(1002, 3000.0); // Account 2 with Rs 3000

    // Display initial balances
    cout << "Initial Balances:" << endl;
    cout << "Account 1:" << endl;
    account1.display();
    cout << "Account 2:" << endl;
    account2.display();

    // Perform money transfer
    double transferAmount;
    cout << "\nEnter the amount to transfer from Account 1 to Account 2: ";
    cin >> transferAmount;

    account1.moneyTransfer(account2, transferAmount);

    // Display updated balances
    cout << "\nUpdated Balances:" << endl;
    cout << "Account 1:" << endl;
    account1.display();
    cout << "Account 2:" << endl;
    account2.display();

    return 0;
}

/*OUTPUT
Initial Balances:
Account 1:
Account Number: 1001
Balance: Rs 5000
Account 2:
Account Number: 1002
Balance: Rs 3000

Enter the amount to transfer from Account 1 to Account 2: 900
Transfer successful!
Rs 900 transferred from Account 1001 to Account 1002.

Updated Balances:
Account 1:
Account Number: 1001
Balance: Rs 4100
Account 2:
Account Number: 1002
Balance: Rs 3900

daria@DG MINGW64 ~/OneDrive/Documents/New
$ ./cons
Initial Balances:
Account 1:
Account Number: 1001
Balance: Rs 5000
Account 2:
Account Number: 1002
Balance: Rs 3000

Enter the amount to transfer from Account 1 to Account 2: 25000
Transfer failed! Insufficient balance in Account 1001.
Minimum balance of Rs 1000 must be maintained.

Updated Balances:
Account 1:
Account Number: 1001
Balance: Rs 5000
Account 2:
Account Number: 1002
Balance: Rs 3000
*/
