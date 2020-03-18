// Age in Days

#include <iostream>
using namespace std;


int main(){
	int age, data[3];
	cin >> age;

	data[2] = age/365;
	age = age%365;
	data[1] = age/30;
	age = age%30;
	data[0] = age;
	cout << data[2] << " ano(s)\n" << data[1] << " mes(es)\n" << data[0] << " dia(s)" << endl;

	return 0;
}