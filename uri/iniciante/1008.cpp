// Salary
#include <iostream>

using namespace std;

int main(){
	int id, h_trabalhada;
	float valor_h;
	cin >> id;
	cin >> h_trabalhada;
	cin >> valor_h;

	cout << fixed;
	cout.precision(2);
	cout << "NUMBER = " << id << "\nSALARY = U$ " << h_trabalhada * valor_h << endl;

	return 0;
}