/*
 * 파일이름:AccountHandler.h
 * 작성자:하창완
 * 업데이트 정보:[2022.01.03] ver.final
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler{
	private:
		BoundCheckArray<Account*> accArr;
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
