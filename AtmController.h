/*
*
* AtmController.h
*
* Created on Dec 26 2020
*      Author: Animesh Nema 
*			   anema@wpi.edu
*/

#pragma once
#include"Bank.h"
#include<vector>
#include<string>
#include<map>

/*	class Atm
	brief This class mimics the use of ATM and allows the user to make changes
	to an account after it has been validated. This class also inherits public methods of Bank.
*/
class Atm : public Bank
{
private:
	bool m_is_valid; // to check whether card info and PIN are validated ot not.
	int m_acc_type; // ( (0 : Savings) , (1 : Checking) , (-1 : Invalid Response)) 
	int m_card_number; //card number for the inserted card.
	int m_cash_bin; // Total cash remaining in the ATM.
	std::map<int,int> m_customer_data; // map that contains account type and balance for inserted card.
	Bank m_bank; //Class Bank Object.

public:

	Atm(Bank bank, int cash_bin); //Contsructor
	~Atm(); // Destructor

	/*
		insertCard - Checks if card number and PIN match by calling Bank::ValidatePIN.
		return - bool value (m_is_valid).
	 */
	bool insertCard(int card_number, int pin_number);

	/*
		selectAccount - Allows user to select account type (Savings or Checking to perform an action.
		@param account_type  - 0(Savings)
							   1(Checking)
		
		return - 0 or 1 or  -1(Invalid Response).
	 */
	int selectAccount(int account_type);

	/*
		dashboard - Allows various options for selected account type. (Once the pin is validated and account type is chosen).
		@param option - 0(See Balance)
						1(Deposit Cash)
						2(Withdraw Cash)

		@param amount - Amount the user would like to deposit or withdraw.
	 */
	void dashboard(int option, int amount);

	/*
		testController' is written to perform various tests on class Atm.
	
		@param account_type  - 0(Savings)
							   1(Checking)
	
		@param option - 0(See Balance)
						1(Deposit Cash)
						2(Withdraw Cash)
	*/
	void testController(int card_number, int pin_number, int account_type, int option, int amount);
};

