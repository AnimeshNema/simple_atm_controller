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
	bool isValid =false;
	int account_type = -1;
	Bank bank = Bank();
	bank_database = bank.addCustomer(12345678, 2323,"SAVINGS", 1000);
	bank_database = bank.addAccount(12345678, "CHECKING", 1200);
	bank_database = bank.addCustomer(87654321, 8765, "SAVINGS", 500);
	bank_database = bank.addCustomer(87654321, 8765, "SAVINGS", 600);
	bank_database = bank.addCustomer(23817642, 6745, "SAVINGS", 60);
	bank_database = bank.addAccount(23817642, "CHECKING", 1600);

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
	* 
	*/
	atm.testController(12345678, 2323, 0, 0, 0);
	std::cout << "-------------------------------------------- " << std::endl;
	std::cout << " " << std::endl;

	atm.testController(87654321, 8765, 0, 1, 250);
	atm.dashboard(0, 0);
	std::cout << "-------------------------------------------- " << std::endl;
	std::cout << " " << std::endl;

	atm.testController(23817642, 6745, 1, 2, 500);
	atm.dashboard(0, 0);
	std::cout << "-------------------------------------------- " << std::endl;
	std::cout << " " << std::endl;

	atm.testController(12345678, 2373, 0, 0, 0);
	std::cout << "-------------------------------------------- " << std::endl;

}


