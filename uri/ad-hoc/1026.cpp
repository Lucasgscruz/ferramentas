// Carrega ou não Carrega?

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void toBin(long unsigned int a, vector<int>& binario){
	int i = 0;
	for(i = 0; a > 1; i++){
		binario[i] = a % 2;
		a /= 2; 
	}
	binario[i] = a;
}

vector<int> mofiz(vector<int>& n1, vector<int>& n2){
	int tam = n1.size();
	vector<int> total(tam);

	for(int i = 0; i < tam; i++){
		// if(n1[i] == n2[i])
		// 	total[i] = 0;
		// else
		// 	total[i] = 1;
		total[i] = n1[i] ^ n2[i];
	}

	return total;
}

long unsigned int toDec(vector<int> binario){
	long unsigned int soma = 0;
	int tam = binario.size();

	for(int i = 0; i < tam; i++){
		soma += binario[i] * pow(2,i);
	}
	return soma;
}

// template <typename T>
// void show(vector<T> vetor){
// 	int tam = vetor.size();
// 	cout << endl;
// 	for(int i = 0; i < tam; i++)
// 		cout << vetor[i] << " ";
// 	cout << endl;
// }


int main(){
	long unsigned int a, b, soma = 0;


	while(cin >> a >> b){
		long unsigned int tam = 0;

		if(a == 0 && b == 0)
			tam = 32;
		else if(a == 0 || b == 0)
			tam = (a == 0) ? 1 + (log10(b)/log10(2)) : 1 + (log10(a)/log10(2));
		else
			tam = (a > b) ? 1 + (log10(a)/log10(2)) : 1 + (log10(b)/log10(2));
		

		vector<int> a_binario(tam);
		vector<int> b_binario(tam);
		vector<int> total(tam);

		toBin(a, a_binario);
		toBin(b, b_binario);

		total = mofiz(a_binario, b_binario);
		
		cout << toDec(total) << endl;
	}
	return 0;
}