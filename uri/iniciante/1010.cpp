//Simple Calculate
#include <iostream>

using namespace std;

int main(){
	int cod, units;
	float price, total = 0;
	for(int i = 0; i < 2; i++){
		cin >> cod;
		cin >> units;
		cin >> price;
		total += units * price;
	}
	cout << fixed;
	cout.precision(2);
	cout << "VALOR A PAGAR: R$ "<< total << endl;
	return 0;
}