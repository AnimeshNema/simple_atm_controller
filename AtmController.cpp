#include "AtmController.h"
#include<iostream>

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


















