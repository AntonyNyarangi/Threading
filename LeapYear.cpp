#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

void *divisibleBy4 (void *pyear)
{
	int year;
	
	pthread_exit(NULL);
}

void *divisibleBy100AND400 (void *pyear)
{
	int year;
	&year = pyear;
	//cout << year << endl;
	// if ((year % 100 ==0) && (year % 400 == 0))
	// {
	// 	return 1;
	// }
	// else
	// {
	// 	return 0;
	// }
	pthread_exit(NULL);
}

int main()
{
	int year;
	cout << "please enter the year you would like to test" << endl;
	cin >> year;	

	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1,NULL,divisibleBy4,&year;
	//pthread_join(thread1,NULL);

	pthread_create(&thread2,NULL,divisibleBy100AND400,&year);	
	//pthread_join(thread2,NULL);


}


