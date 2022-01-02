/*
 * 파일이름:NormalAccount.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.03] ver.final
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"
#include "AccountException.h"

class NormalAccount : public Account{
	private:
		int interRate;            //이자율
	public:
		NormalAccount(int ID, int money, String name, int rate)
			:Account(ID, money, name), interRate(rate) {}

		virtual void Deposit(int money){
			if(money<0)
				throw MinusException(money);

			Account::Deposit(money);                        //원금
			Account::Deposit(money*(interRate/100.0));      //이자추가
		}
};
#endif
