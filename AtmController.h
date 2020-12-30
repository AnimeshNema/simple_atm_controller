#pragma once
#include"Bank.h"
#include<vector>
#include<string>
#include<map>

//struct AccountInformation {
//	int s_pin_number;
//	int s_card_number;
//	std::map<int,int> s_acc_and_balance;
//};
//
//class Bank
//{
//private:
//	std::vector<AccountInformation> m_data;
//	
//public:
//	Bank();
//	~Bank();
//	std::vector<AccountInformation> addCustomer(int card_number, int pin_number, std::string account_type, int balance);
//	std::vector<AccountInformation> addAccount(int card_number, std::string account_type, int balance);
//	std::map<int, int> validatePIN(int card_number, int pin_number);
//	void updateBalance(int card_number, int account_type, int amount);
//	std::map<int, int> m_invalid_information;
//};

class Atm : public Bank
{
private:
	bool m_is_valid;
	int m_acc_type;
	int m_card_number;
	int m_cash_bin;
	std::map<int,int> m_customer_data;
	std::vector<AccountInformation> m_atm_data;
	Bank m_bank;

public:
	Atm(Bank bank, int cash_bin);
	~Atm();
	bool insertCard(int card_number, int pin_number);
	int selectAccount(int account_type);
	void dashboard(int option, int amount);
	void testController(int card_number, int pin_number, int account_type, int option, int amount);
};

