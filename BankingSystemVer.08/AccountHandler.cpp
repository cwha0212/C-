/*
 * 파일이름:AccountHandler.cpp
 * 작성자:하창완
 * 업데이트 정보:[2022.01.01] ver.07
 */

#include "Account.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

void AccountHandler::ShowMenu(void) const{
	cout << "--------메뉴--------" << endl;
	cout << "1.  계좌개설" << endl;
	cout << "2.  입금" << endl;
	cout << "3.  출금" << endl;
	cout << "4.  계좌정보 전체 출력" << endl;
	cout << "5.  프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void){
	int sort;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌" << endl;
	cout << "2.신용신뢰계좌" << endl;
	cout << "선택";
	cin >> sort;

	if(sort==NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void){
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << endl;

	accArr[accNum++]=new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void){
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급(1 to A, 2 to B, 3 to C): "; cin >> creditLevel;
	cout << endl;

	switch(creditLevel){
		case 1:
			accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
			break;
		case 2:
			accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
			break;
		case 3:
			accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
			break;
	}
}

void AccountHandler::DepositMoney(void){
	int money;
	int id;
	cout << "[입금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for(int i=0; i<accNum; i++){
			if(accArr[i]->GetAccID()==id){
				accArr[i]->Deposit(money);
				cout << "입금완료" << endl << endl;
				return;
			}
	}
	cout << "유효하지 않은 ID 입니다."<< endl << endl;
}

void AccountHandler::WithdrawMoney(void){
	int Money;
	int id;
	cout << "[출금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> Money;
	for(int i=0; i<accNum; i++){
		if(accArr[i]->GetAccID()==id){
			if(accArr[i]->Withdraw(Money)==0){
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const {
	for(int i=0; i<accNum; i++){
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::AccountHandler() :accNum(0) {}

AccountHandler::~AccountHandler(){
	for(int i=0; i<accNum; i++){
		delete accArr[i];
	}
}
