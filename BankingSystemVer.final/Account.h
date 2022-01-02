/*
 * 파일이름:Account.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.03] ver.final
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account{
	private:
		int accID;                 //계좌번호
		int balance;               //잔액
		String cusName;            //고객번호

	public:
		Account(int ID, int money, String name);
		int GetAccID() const;
		virtual void Deposit(int money);
		int Withdraw(int money);
		void ShowAccInfo() const;
};
#endif
