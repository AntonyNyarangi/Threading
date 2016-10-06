#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>

using namespace std;

// int accountNumber; //identifier of the account
// int availableBalance; //amount of money in Ksh in bank
// bool accountStatus; //1 will represent open and 0 closed


int accountNumber = 111222333;
int availableBalance = 500000;
bool accountStatus = true;



//**************************************************************//
void Withdrawal(){
	if (accountStatus != true){
		cout << "Sorry, this account is closed" << endl;
	}
	else{
		int withdrawalAmount;
		cout << "How much would you like to withdraw?" << endl;
		cin >> withdrawalAmount;
		if (withdrawalAmount > availableBalance){
			cout << "Insufficient Balance" << endl;
		}
		else{
			availableBalance = availableBalance - withdrawalAmount;
			cout << "Your new balance is: " << availableBalance << endl;
		}
	}
	pthread_exit(NULL);
}
//**************************************************************//
void Deposit(){
	if (accountStatus != true){
		cout << "Sorry, this account is closed" << endl;
	}
	else{
		int depositAmount;
		cout << "How much would you like to deposit?" << endl;
		cin >> depositAmount;
		if (depositAmount < 0){
			cout << "You cannot deposit a negative amount" << endl;

		}
		else{
			availableBalance = availableBalance + depositAmount;
			cout << "Your new balance is: " << availableBalance << endl;
		}
	}	
	pthread_exit(NULL);
}
//**************************************************************//
void CloseAccount(){
	if (accountStatus != true){
		cout << "Sorry, this account is already closed" << endl;
	}
	else{
		accountStatus = false;
	}
	pthread_exit(NULL);
}
//**************************************************************//
void *MobileAccess(void *){

	cout << endl << "MOBILE PHONE ACCESS" << endl;

	char choice;
	cout <<"Please select an action from the list below"<<endl;
	cout <<"1) Withdrawal"<<endl;
	cout <<"2) Deposit"<<endl;
	cout <<"3) Close Account"<<endl;
	cout <<"4) Exit"<<endl;
	cin >> choice;

	switch (choice){
		case '1': Withdrawal();
		break;
		case '2': Deposit();
		break;
		case '3': CloseAccount();
		break;		
		case '4': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		MobileAccess(NULL);
	}
	return NULL;
}
//**************************************************************//
void *InternetAccess(void *){

	cout << endl << "INTERNET ACCESS" << endl;

	char choice;
	cout <<"Please select an action from the list below"<<endl;
	cout <<"1) Withdrawal"<<endl;
	cout <<"2) Deposit"<<endl;
	cout <<"3) Close Account"<<endl;
	cout <<"4) Exit"<<endl;
	cin >> choice;

	switch (choice){
		case '1': Withdrawal();
		break;
		case '2': Deposit();
		break;
		case '3': CloseAccount();
		break;		
		case '4': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		InternetAccess(NULL);
	}
	return NULL;
}
//**************************************************************//
int main(){

	// pthread_t bankThreads[2];
	// int i;
	// for(i = 1; i = 2; i++){
	// 	cout << "Creating thread, "<< i
	// }
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1,NULL,MobileAccess,NULL);
	pthread_join(thread1,NULL);
	pthread_create(&thread2,NULL,InternetAccess,NULL);
	pthread_join(thread2,NULL);

	return 0;
}