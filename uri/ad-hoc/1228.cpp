// Grid de largada
// bubble sort simulando ultrapassagens

#include <iostream>
#include <vector>
using namespace std;

typedef struct Carro {
	int id;
	int largada;
} carro;

void swap(int &a, int &b){ 
    int temp = a; 
    a = b; 
    b = temp; 
}

int main(){
	int N = 1;

	while(cin >> N){
		int total = 0;
		vector<carro> carros(N);
		int largada[N];
		int chegada[N];

		for(int i = 0; i < N; i++){
			cin >> carros[i].id;
			carros[i].largada = i;
		}

		for(int i = 0; i < N; i++){
			int aux;
			cin >> aux;
			for(int j = 0; j < N; j++){
				if(aux == carros[j].id){
					chegada[j] = i;
					break;
				}
			}
		}

		int tam = carros.size();
		// Ordenaçao bubble sort
		for (int i = tam-1; i > 0; i--){
			for (int j = 0; j < i ; j++){
				if(chegada[j] > chegada[j+1]){
					swap(chegada[j], chegada[j+1]);
					total++;
				}
			}	
		}

		cout << total << endl;
	}

	return 0;
}
