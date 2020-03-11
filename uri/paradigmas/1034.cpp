// Festival de Estátuas de Gelo
// Adapatação do problema do troco utilizando programação dinamica

#include <iostream>
#include <vector>


using namespace std;

typedef struct{
	int N; // Numero de tipos diferentes de blocos
	int comprimento; // comprimento desejado pelo artista
	vector<int> blocos;

	int cortarBlocos(){
		int contador, qual_pegar;
		vector<int> cont(comprimento + 1);

		for(int i = 1; i < comprimento + 1; i++){
			contador = i;
			for(int j: blocos){
				if(j <= i){
					if(cont[i-j] + 1 < contador){
						contador = cont[i-j] + 1;
					}
				}
				cont[i] = contador;					
			}
		}

		return cont[comprimento];
	}


} Geleira;

int main(){
	int testes; // casos de teste
	Geleira bloco;

	cin >> testes;
	while(testes){
		cin >> bloco.N;
		cin >> bloco.comprimento;
		
		for(int i = 0, aux; i < bloco.N; i++){
			cin >> aux;
			bloco.blocos.push_back(aux);
		}

		cout << bloco.cortarBlocos() << endl;
		bloco.blocos.clear();

		testes--;
	}
	return 0;
}