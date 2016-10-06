
/* CSC 223 Assignment 1
 
Title:
-----
Bank Account

Names & RegNo 
-------------
Antony Momanyi Nyarangi (P15/33522/2015)
Adah Meda Odhiambo (P15/33828/2015)

Date:Oct 6 2016*/

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>

using namespace std;

pthread_mutex_t balanceMutex;


int accountNumber = 111222333;//identifier of the account
int availableBalance = 500000;//amount of money in Ksh in bank
bool accountStatus = true;//true will represent open and false, closed


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
void *IncomingWirelessTransfer(void*){
	if (accountStatus != true){
		cout << "Money Transfer failed, account closed" << endl;
	}
	else{
		pthread_mutex_lock(&balanceMutex);
		cout << endl << "Available balance variable locked due to incoming wire transfer" << endl;
		int incomingAmount = rand() % (500000 - 20000 + 1) + 20000;
		cout << "..." << endl;		
		availableBalance = availableBalance + incomingAmount;
		cout << "Transfer completed, variable unlocked. New Balance: " << availableBalance << endl << endl;
		pthread_mutex_unlock(&balanceMutex);
	}
	pthread_exit(NULL);
}
//**************************************************************//
int main(){	
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	
	pthread_create(&thread2,NULL,MobileAccess,NULL);
	pthread_create(&thread1,NULL,IncomingWirelessTransfer,NULL);
	pthread_join(thread2,NULL);
	pthread_create(&thread3,NULL,InternetAccess,NULL);
	pthread_join(thread3,NULL);

	return 0;
}
