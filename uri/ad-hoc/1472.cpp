#include <iostream>

using namespace std;

bool buscaBinaria(int* vet, int chave, int Tam){
     int inf = 0;     // limite inferior (o primeiro índice de vetor eh 0)
     int sup = Tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     while (inf <= sup){
          meio = (inf + sup)/2;
          if (chave == vet[meio])
               return true;
          if (chave < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return false;   // não encontrado
}

int main(){
	int N, total, lado;

	while(cin >> N){
		total = 0;

		int pontos[N], arr[N];
		cin >> pontos[0];
		arr[0] = pontos[0];

		for(int i = 1; i < N; i++){
			cin >> pontos[i];
			arr[i] = arr[i-1] + pontos[i];
		}

		lado = arr[N-1] / 3;
		if(arr[N-1] % 3 != 0){
			cout << total << endl;
		 	continue;
		}

		for(int i = 0; i < N; i++){
			if(buscaBinaria(arr, lado + arr[i], N))
				if(buscaBinaria(arr, 2 * lado + arr[i], N))
					total++;
		}
		cout << total << endl;
	}

	return 0;
}