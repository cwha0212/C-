/*
 * 파일이름:HighCreditAccount.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.03] ver.final
 */

#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount{
	private:
		int specialRate;
	public:
		HighCreditAccount(int ID, int money, String name, int rate, int special)
			:NormalAccount(ID, money, name, rate), specialRate(special) {}
		virtual void Deposit(int money){
			if(money<0)
				throw MinusException(money);

			NormalAccount::Deposit(money);                 //원금,이자추가
			Account::Deposit(money*(specialRate/100.0));   //특별이자추가
		}
};

#endif
