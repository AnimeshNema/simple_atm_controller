#pragma once
#include"Bank.h"
#include<vector>
#include<string>
#include<map>

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

