// Banknotes

#include <iostream>
using namespace std;

typedef struct note {
	int value;
	int amount;
} Note;

int main(){
	int value;
	Note notes[] = {{100}, {50}, {20}, {10}, {5}, {2}, {1}};

	cin >> value;

	for(int i = 0, aux = value; aux > 0; i++){
		notes[i].amount = aux / notes[i].value;
		aux -= notes[i].value * notes[i].amount;
	}

	cout << value << endl;
	for(int i = 0; i < 7; i++){
		cout << notes[i].amount << " nota(s) de R$ " << notes[i].value << ",00" << endl;
	}
	return 0;
}