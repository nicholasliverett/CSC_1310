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
        /** @brief constructor assign name, account num, and balance
         *  @param name account holder name
         *  @param num account number
         *  @param bal account balance
         */
        BankAccount(string name, int num, double bal) {
            accountHolderName = name;
            accountNumber = num;
            balance = bal;
        }
        /** @brief Print deposited amount and add to account balance
         *  @param amount deposit amount
         */
        void deposit(double amount) {
            cout << "Deposited: $" << amount << endl;
            balance += amount;
        }
        /** @brief Print withdrawn amount and remove from account balance
         *      if there is enough in the balance to withdraw
         *  @param amount withdraw amount
         */
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: $" << amount << endl;
            } else
                cout << "Insufficient Balance!\n";
        }
        /** @brief Return balance
         */
        double getBalance() const {
            return balance;
        }
        /** @brief Print account info
         */
        void displayAccountInfo() const {
            cout << "\nAccount Holder: " << accountHolderName;
            cout << "\nAccount Number: " << accountNumber;
            cout << "\nCurrent Balance: $" << balance;
            cout << "\n--------------------------------\n\n";
        }
};
int main()
{
    // Initialize myaccout var with data
    BankAccount myAccount("John Doe", 123456, 500.00);

    myAccount.displayAccountInfo();

    // Showcase deposit function
    myAccount.deposit(150.00);
    cout << "After depositing $150:";
    myAccount.displayAccountInfo();

    // Showcase deposit function
    myAccount.withdraw(100.00);
    cout << "After withdrawing $100:";
    myAccount.displayAccountInfo();

    // Shocase withdraw function failing
    myAccount.withdraw(600.00);
    cout << "After attempting to withdraw $600:";
    myAccount.displayAccountInfo();


    return 0;
}