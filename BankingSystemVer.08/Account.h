/*
 * 파일이름:Account.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.02] ver.08
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account{
	private:
		int accID;                 //계좌번호
		int balance;               //잔액
		char *cusName;             //고객번호

	public:
		Account(int ID, int money, char *name);
		Account(const Account & ref);
		Account& operator=(const Account& ref);

		int GetAccID() const;
		virtual void Deposit(int money);
		int Withdraw(int money);
		void ShowAccInfo() const;
		~Account();
};
#endif
