/*
 * 소프트웨어 버전:Banking System Ver final
 *
 * 파일이름:BankingSystemMain.cpp
 * 작성자:하창완
 * 업데이트 정보:[2022.01.03] ver.final
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main (void){
	AccountHandler manager;
	int choice;

	while(1){
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch(choice){
			case MAKE:
				manager.MakeAccount();
				break;
			case DEPOSIT:
				manager.DepositMoney();
				break;
			case WITHDRAW:
				manager.WithdrawMoney();
				break;
			case INQUIRE:
				manager.ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				cout << "유효하지 않은 입력입니다. 다시 입력하시오" << endl << endl;
		}
	}
	return 0;
}
