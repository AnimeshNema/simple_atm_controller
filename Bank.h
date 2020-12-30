#pragma once
#include<vector>
#include<string>
#include<map>

struct AccountInformation {
	int s_pin_number;
	int s_card_number;
	std::map<int, int> s_acc_and_balance;
};

class Bank
{
private:
	std::vector<AccountInformation> m_data;

public:
	Bank();
	~Bank();
	std::vector<AccountInformation> addCustomer(int card_number, int pin_number, std::string account_type, int balance);
	std::vector<AccountInformation> addAccount(int card_number, std::string account_type, int balance);
	std::map<int, int> validatePIN(int card_number, int pin_number);
	void updateBalance(int card_number, int account_type, int amount);
	std::map<int, int> m_invalid_information;
};
