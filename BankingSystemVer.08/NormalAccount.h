/*
 * 파일이름:NormalAccount.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.01] ver.07
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account{
	private:
		int interRate;            //이자율
	public:
		NormalAccount(int ID, int money, char *name, int rate)
			:Account(ID, money, name), interRate(rate) {}

		virtual void Deposit(int money){
			Account::Deposit(money);                        //원금
			Account::Deposit(money*(interRate/100.0));      //이자추가
		}
};
#endif
