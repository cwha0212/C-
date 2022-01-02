/*
 * 파일이름:Account.cpp
 * 작성자:하창완
 * 업데이트 정보:[2022.01.02] ver.08
 */

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, String name)
	:accID(ID), balance(money)
{
	cusName=name;
};

int Account::GetAccID() const {
	return accID;
};

void Account::Deposit(int money){
	balance+=money;
};

int Account::Withdraw(int money){
	if(balance<money)
		return 0;

	balance-=money;
	return money;
};

void Account::ShowAccInfo() const {
	cout << "계좌ID: " << accID << endl;
	cout << "이름: " << cusName << endl;
	cout << "잔액: " << balance << endl << endl;
};
