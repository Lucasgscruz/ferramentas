// Salary with bonus
#include <iostream>
using namespace std;

int main(){
	string name;
	double salary, sales;

	cin >> name;
	cin >> salary;
	cin >> sales;

	cout << fixed;
	cout.precision(2);
	cout << "TOTAL = R$ " << salary + (sales * 0.15) << endl;
	return 0;
}