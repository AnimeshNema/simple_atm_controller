/*
*
* Bank.h
*
* Created on Dec 26 2020
*       Author: Animesh Nema
*
*/

#pragma once
#include<vector>
#include<string>
#include<map>
 
struct AccountInformation { // struct to contain information aoout a single cutomer.
	int s_pin_number;
	int s_card_number;
	std::map<int, int> s_acc_and_balance; // map that contains respective accounts and balance in them.
};

// class Bank
// This class contains methods to generate and store bank database.
class Bank
{
private:
	std::vector<AccountInformation> m_data; // stores entire bank database. 

public:
	Bank(); // Default Constructor
	~Bank(); //Destructor

	/*
	   addCustomer - Adds a user defined entry into m_data(Bank database) if it doesn't already exist.
	 */
	std::vector<AccountInformation> addCustomer(int card_number, int pin_number, std::string account_type, int balance);

	/*
	   addAccount - Adds an additional account (Savings or Checking) for an existing customer.
	 */
	std::vector<AccountInformation> addAccount(int card_number, std::string account_type, int balance);

	/*
	   ValidatePIN - validates the PIN for a card number on the request of ATM controller.
	 */
	std::map<int, int> validatePIN(int card_number, int pin_number);

	/*
	   updateBalance- Updates the balance of the customer after the customer deposits/withdraws cash.
	 */
	void updateBalance(int card_number, int account_type, int amount);

	std::map<int, int> m_invalid_information; // map for invalid cases 
};
