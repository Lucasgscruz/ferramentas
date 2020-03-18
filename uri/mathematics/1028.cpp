// Figurinhas
// Algoritmos de euclides para calcular MDC

#include <iostream>

using namespace std;

int main(){
	int N, deck1, deck2;
	cin >> N;

	while(N){
		int resto;
		cin >> deck1 >> deck2;
		resto = deck1 % deck2;

		while(resto != 0){
			deck1 = deck2;
			deck2 = resto;
			resto = deck1 % deck2;
		}

		cout << deck2 << endl;

		N--;
	}

	return 0;
}
