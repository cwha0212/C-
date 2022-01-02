/*
 * 파일이름:AccountHandler.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.02] ver.08
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler{
	private:
		BoundCheckAccountPtrArray accArr;
		int accNum;
	public:
		AccountHandler();
		void ShowMenu(void) const;
		void MakeAccount(void);
		void DepositMoney(void);
		void WithdrawMoney(void);
		void ShowAllAccInfo(void) const;
		~AccountHandler();
	protected:
		void MakeNormalAccount(void);
		void MakeCreditAccount(void);
};

#endif
