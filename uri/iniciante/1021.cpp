#include <iostream>
using namespace std;

typedef struct nota {
	double price;
	int amount = 0;
} Nota;

int main(){
	double value = 0;
	Nota notes[] = {{10000}, {5000}, {2000}, {1000}, {500}, {200}, {100}, {50}, {25}, {10}, {5}, {1}};

	cin >> value;
	value *= 100;

	int aux = 0;
	for(int i = 0; i < 12; i++){
		aux = value / notes[i].price;
		value -= aux*notes[i].price;
		notes[i].amount = aux;
	}

	cout << fixed;
	cout.precision(2);
	cout << "NOTAS:" << endl;
	for(int i = 0; i < 6; i++){
		cout << notes[i].amount << " nota(s) de R$ " << notes[i].price/100 << endl;
	}
	cout << "MOEDAS:" << endl;
	for(int i = 6; i < 12; i++){
		cout << notes[i].amount << " moeda(s) de R$ " << notes[i].price/100 << endl;
	}
	return 0;
}