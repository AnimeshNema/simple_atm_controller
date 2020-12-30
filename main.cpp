/*
*
* main.cpp
*
* Created on Dec 26 2020
*       Author: Animesh Nema
*
*/

#include<iostream>
#include"AtmController.h"

int main()
{
	std::vector<AccountInformation> bank_database;
	bool isValid = false;
	Bank bank = Bank();

	// Add Customers and accounts in the Bank.
	bank_database = bank.addCustomer(12345678, 2323,"SAVINGS", 1000);
	bank_database = bank.addAccount(12345678, "CHECKING", 1200);

	bank_database = bank.addCustomer(87654321, 8765, "SAVINGS", 500);
	bank_database = bank.addCustomer(87654321, 8765, "SAVINGS", 600); //This will be ignored as the card_number already exists
	
	bank_database = bank.addCustomer(23817642, 6745, "SAVINGS", 100);
	bank_database = bank.addAccount(23817642, "CHECKING", 1600);

	bank_database = bank.addCustomer(13572468, 7777, "SAVINGS", 2000);

	bank_database = bank.addCustomer(44445555, 9999, "SAVINGS", 800);
	bank_database = bank.addAccount(44445555, "CHECKING", 11000);

	// Initialize the Atm with int cash_bin.

	int cash_bin = 10000; // $10,000
	Atm atm(bank, 10000);

	/*
	* function 'testController' performs an action on each call.
	* It's parameters are [int card number, int pin number, int account type, int option, int amount]
	* 
	* int account type - has three valid responses
	*	0 - "SAVINGS Account"
	*	1 - "CHECKING Account"
	* 
	* int option - has three valid responses
	*	0 - "See Balance"
	*	1 - "Deposit Cash Amount"
	*	2 - "Withdraw Cash Amount"
	*/

	// Case I- Case should run Succesfully. Should display Balance.
	atm.testController(12345678, 2323, 0, 0, 0);
	std::cout << "-------------------------------------------- " << std::endl;
	std::cout << " " << std::endl;

	// Case II- Case should run Succesfully. Should deposit $250 in Savings 
	// and show new balance.
	atm.testController(87654321, 8765, 0, 1, 250);
	atm.dashboard(0, 0);
	std::cout << "-------------------------------------------- " << std::endl;
	std::cout << " " << std::endl;

	// Case III- Case should run Succesfully. Should deposit $500 in Checking
	// and show new balance.
	atm.testController(23817642, 6745, 1, 1, 500);
	atm.dashboard(0, 0);
	std::cout << "-------------------------------------------- " << std::endl;
	std::cout << " " << std::endl;

	// Case IV- Case should Fail. Pin and Card details don't Match.
	atm.testController(23817642, 2372, 0, 0, 0);
	std::cout << "-------------------------------------------- " << std::endl;

	// Case V- Case should Fail. Account type doesn't exist.
	atm.testController(13572468, 7777, 1, 1, 10);
	std::cout << "-------------------------------------------- " << std::endl;

	// Case VI- Case should run Succesfully. Should withdraw $1200 from Savings
	// and show new balance
	atm.testController(13572468, 7777, 0, 2, 1200);
	atm.dashboard(0, 0);
	std::cout << "-------------------------------------------- " << std::endl;

	// Case VII- Case should Fail. Not Enough Balance.
	atm.testController(44445555, 9999, 0, 2, 2000);
	std::cout << "-------------------------------------------- " << std::endl;

	// Case VIII- Case should Fail. Not Enough Cash in ATM.
	atm.testController(44445555, 9999, 1, 2, 11000);
	std::cout << "-------------------------------------------- " << std::endl;
}


