/*
*
* Bank.cpp
*
* Created on Dec 26 2020
*       Author: Animesh Nema
*
*/

#include<iostream>
#include "Bank.h"

Bank::Bank()
{
	m_invalid_information[-1] = -1;
}

Bank::~Bank()
{

}

std::vector<AccountInformation> Bank::addCustomer(int card_number, int pin_number, std::string account_type, int balance)
{
	bool l_card_exists = false;
	if (m_data.size() > 0)
	{
		for (int i = 0; i < m_data.size(); i++)
		{
			if (card_number == m_data[i].s_card_number)
				l_card_exists = true;
		}
	}

	if (l_card_exists != true)
	{
		AccountInformation obj;
		obj.s_card_number = card_number;
		obj.s_pin_number = pin_number;

		if (account_type == "SAVINGS")
		{
			obj.s_acc_and_balance[0] = balance;
		}

		else if (account_type == "CHECKING")
		{
			obj.s_acc_and_balance[1] = balance;
		}

		m_data.push_back(obj);
	}
	return m_data;
}

std::vector<AccountInformation> Bank::addAccount(int card_number, std::string account_type, int balance)
{
	for (int i = 0; i < m_data.size(); i++)
	{
		if (card_number == m_data[i].s_card_number)
		{
			if (account_type == "SAVINGS")
			{
				m_data[i].s_acc_and_balance[0] = balance;
			}

			else if (account_type == "CHECKING")
			{
				m_data[i].s_acc_and_balance[1] = balance;
			}
		}
	}
	return m_data;
}

std::map<int, int> Bank::validatePIN(int card_number, int pin_number)
{
	bool l_pin_valid = false;
	if (m_data.size() != 0)
	{
		for (int i = 0; i < m_data.size(); i++)
		{
			if (card_number == m_data[i].s_card_number && pin_number == m_data[i].s_pin_number)
			{
				l_pin_valid = true;
				std::cout << "PIN Validated" << std::endl;
				return m_data[i].s_acc_and_balance;
			}
		}

		if (l_pin_valid != true)
		{
			std::cout << "Pin Invalid for this Card" << std::endl;
			return m_invalid_information;
		}

	}
	else
	{
		std::cout << "Bank is Empty!" << std::endl;
		return m_invalid_information;
	}
}

void Bank::updateBalance(int card_number, int account_type, int amount)
{
	for (int i = 0; i < m_data.size(); i++)
	{
		if (card_number == m_data[i].s_card_number)
		{
			if (m_data[i].s_acc_and_balance.find(account_type) != m_data[i].s_acc_and_balance.end())
			{
				m_data[i].s_acc_and_balance[account_type] = amount;
			}

			else
			{
				std::cout << "Account type Incorrect" << std::endl;
			}
		}
	}
}

