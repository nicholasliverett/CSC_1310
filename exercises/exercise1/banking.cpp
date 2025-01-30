/** @file   "banking.cpp"
 *  @author Nicholas Liverett
 *  @date   1/30/25
 * 
 *  @brief  Class exercise 1
 */

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
        string accountHolderName;
        int accountNumber;
        double balance;
    public:
        BankAccount(string name, int num, double bal) {
            accountHolderName = name;
            accountNumber = num;
            balance = bal;
        }
        void deposit(double amount) {
            cout << "Deposited: $" << amount << endl;
            balance += amount;
        }
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: $" << amount << endl;
            } else
                cout << "Insufficient Balance!\n";
        }
        double getBalance() const {
            return balance;
        }
        void displayAccountInfo() const {
            cout << "\nAccount Holder: " << accountHolderName;
            cout << "\nAccount Number: " << accountNumber;
            cout << "\nCurrent Balance: $" << balance;
            cout << "\n--------------------------------\n\n";
        }
};
int main()
{
    BankAccount myAccount("John Doe", 123456, 500.00);

    myAccount.displayAccountInfo();

    myAccount.deposit(150.00);
    cout << "After depositing $150:";
    myAccount.displayAccountInfo();

    myAccount.withdraw(100.00);
    cout << "After withdrawing $100:";
    myAccount.displayAccountInfo();

    myAccount.withdraw(600.00);
    cout << "After attempting to withdraw $600:";
    myAccount.displayAccountInfo();


    return 0;
}