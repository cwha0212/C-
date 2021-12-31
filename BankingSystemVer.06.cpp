/*
 * Banking System Ver.0.6
 * 작성자:하창완
 * 내 용:이자관련 계좌 클래스 추가
 */

#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

enum {MAKE=1 ,DEPOSIT, WITHDRAW, INQUIRE, EXIT}; //메뉴

enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};          //신용등급

enum {NORMAL=1, CREDIT};                         //계좌종류

/*
 * 클래스 이름: Account
 * 클래스 유형: Entity 클래스
 */

class Account{
	private:
		int accID;                 //계좌번호
		int balance;               //잔액
		char *cusName;             //고객번호

	public:
		Account(int ID, int money, char *name);
		Account(const Account & ref);

		int GetAccID() const;
		virtual void Deposit(int money);
		int Withdraw(int money);
		void ShowAccInfo() const;
		~Account();
};


Account::Account(int ID, int money, char *name)
	:accID(ID), balance(money)
{
	cusName=new char [strlen(name)+1];
	strcpy(cusName, name);
};

Account::Account(const Account & ref)
	:accID(ref.accID), balance(ref.balance)
{
	cusName=new char [strlen(ref.cusName)+1];
	strcpy(cusName, ref.cusName);
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

Account::~Account(){
	delete []cusName;
};

/*
 * 클래스 이름: NormalAccount
 * 클래스 유형: Entity 클래스
 */

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

/*
 * 클래스 이름: HighCreditAccount
 * 클래스 유형: Entity 클래스
 */

class HighCreditAccount : public NormalAccount{
	private:
		int specialRate;
	public:
		HighCreditAccount(int ID, int money, char *name, int rate, int special)
			:NormalAccount(ID, money, name, rate), specialRate(special) {}
		virtual void Deposit(int money){
			NormalAccount::Deposit(money);                 //원금,이자추가
			Account::Deposit(money*(specialRate/100.0));   //특별이자추가
		}
};


/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: Control 클래스
 */

class AccountHandler{
	private:
		Account * accArr[100];
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
/*
 * 컨트롤 클래스 AccountHandler 중심으로 변결된 main 함수
 */

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
