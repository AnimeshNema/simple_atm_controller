#include "AtmController.h"
#include<iostream>

//Bank::Bank()
//{
//	m_invalid_information[-1] = -1;
//}
//
//Bank::~Bank()
//{
//
//}
//
//std::vector<AccountInformation> Bank::addCustomer(int card_number, int pin_number, std::string account_type, int balance)
//{
//	bool l_card_exists= false;
//	if (m_data.size() > 0)
//	{
//		for (int i = 0; i < m_data.size(); i++)
//		{
//			if (card_number == m_data[i].s_card_number)
//				l_card_exists = true;
//		}
//	}
//
//	if (l_card_exists !=true)
//	{
//		AccountInformation obj;
//		obj.s_card_number = card_number;
//		obj.s_pin_number = pin_number;
//
//		if (account_type == "SAVINGS")
//		{
//			obj.s_acc_and_balance[0] = balance;
//		}
//
//		else if (account_type == "CHECKING")
//		{
//			obj.s_acc_and_balance[1] = balance;
//		}
//
//		m_data.push_back(obj);
//	}
//	return m_data;
//}
//
//std::vector<AccountInformation> Bank::addAccount(int card_number, std::string account_type, int balance)
//{
//	for (int i =0 ; i < m_data.size(); i++)
//	{
//		if (card_number == m_data[i].s_card_number)
//		{
//			if (account_type == "SAVINGS")
//			{
//				m_data[i].s_acc_and_balance[0] = balance;
//			}
//
//			else if (account_type == "CHECKING")
//			{
//				m_data[i].s_acc_and_balance[1] = balance;
//			}
//		}
//	}
//	return m_data;
//}
//
//std::map<int,int> Bank::validatePIN(int card_number, int pin_number)
//{
//	bool l_pin_valid = false;
//	if (m_data.size() != 0)
//	{
//		for (int i = 0; i < m_data.size(); i++)
//		{
//			if (card_number == m_data[i].s_card_number && pin_number == m_data[i].s_pin_number)
//			{
//				l_pin_valid = true;
//				std::cout << "PIN Validated" << std::endl;
//				return m_data[i].s_acc_and_balance;
//			}
//		}
//		
//		if (l_pin_valid != true)
//		{
//			std::cout << "Pin Invalid for this Card"<<std::endl;
//			return m_invalid_information;
//		}
//
//	}
//	else
//	{	
//		std::cout <<"Bank is Empty!"<<std::endl;
//		return m_invalid_information;
//	}
//}
//
//void Bank::updateBalance(int card_number, int account_type, int amount)
//{
//	for (int i = 0; i < m_data.size(); i++)
//	{
//		if (card_number == m_data[i].s_card_number)
//		{
//			if(m_data[i].s_acc_and_balance.find(account_type) != m_data[i].s_acc_and_balance.end())
//			{
//				m_data[i].s_acc_and_balance[account_type] = amount;
//			}
//
//			else 
//			{
//				std::cout << "Account type Incorrect" << std::endl;
//			}
//		}
//	}
//}

//-----------------------------------------------------------------------------------------------------

Atm::Atm(Bank bank, int cash_bin)
	:m_is_valid(false), m_acc_type(-1), m_bank(bank), m_cash_bin(cash_bin), m_card_number(0)
{

}

Atm::~Atm()
{}

bool Atm::insertCard(int card_number, int pin_number)
{
	m_customer_data.clear();
	m_customer_data = m_bank.validatePIN(card_number, pin_number);

	if (m_customer_data != m_invalid_information)
	{
		m_card_number = card_number;
		m_is_valid = true;
	}

	else
	{
		m_is_valid = false;
	}
	return m_is_valid;
}

int Atm::selectAccount(int account_type)
{
	if (m_is_valid)
	{
		if (account_type == 0)
		{
			m_acc_type = account_type;
			std::cout << "Entered SAVINGS Account" << std::endl;
		}

		else if (account_type == 1)
		{
			m_acc_type = account_type;
			std::cout << "CHECKING Account" << std::endl;
		}

		else
		{
			std::cout << "Invalid Response. Please choose from Savings or Checking account." << std::endl;
			m_acc_type = -1;
		}
	}

	else
	{
		std::cout << "Card_not Validated" << std::endl;
		m_acc_type = -1;
	}

	return m_acc_type;
}

void Atm::dashboard(int option, int amount)
{
	if (m_acc_type != -1)
	{
		if (option == 0)
		{
			if(m_acc_type == 0)
				std::cout << "You have $"<<m_customer_data[m_acc_type]<<" in your SAVINGS account." << std::endl;
			
			else if(m_acc_type == 1)
				std::cout << "You have $" << m_customer_data[m_acc_type] << " in your CHECKING account." << std::endl;
		}

		else if (option == 1)
		{
			m_customer_data[m_acc_type] += amount;
			m_bank.updateBalance(m_card_number, m_acc_type, m_customer_data[m_acc_type]);
			std::cout << "$" << amount << " deposited in your account." << std::endl;
			m_cash_bin += amount;
		}

		else if (option == 2)
		{
			if (m_cash_bin >= amount)
			{
				if (m_customer_data[m_acc_type] >= amount)
				{
					m_customer_data[m_acc_type] -= amount;
					m_bank.updateBalance(m_card_number, m_acc_type, m_customer_data[m_acc_type]);
					std::cout << "$" << amount << " withdrawn from your account." << std::endl;
					m_cash_bin -= amount;
				}

				else
					std::cout << "Not Enough Balance" << std::endl;
			}

			else
				std::cout << "Not enough Cash in ATM" << std::endl;
		}

		else
			std::cout << "Invalid Response" << std::endl;
	}
}



void Atm::testController(int card_number, int pin_number, int account_type, int option, int amount)
{
	m_is_valid = insertCard(card_number, pin_number);
	if (m_is_valid)
	{
		m_acc_type = selectAccount(account_type);
		if (m_acc_type != -1)
		{
			dashboard(option, amount);
		}
	}
}


















