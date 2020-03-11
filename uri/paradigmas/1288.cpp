// Canhão de Destruição - Problema foi reduzido ao problema da mochila
// Problema da mochila - Programação dinamica

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, int wt[], int b[], int n){
	// tabela que será preenchida
	int V[n + 1][W + 1];

	// inicializando a primeira linha e primeira coluna com 0
	for(int w = 0; w <= W; w++)
		V[0][w] = 0;
	for(int i = 1; i <= n; i++)
		V[i][0] = 0;

	for(int k = 0; k < n+1; k++){
		for(int l = 0; l < W+1; l++){
			V[k][l] = 0;
		}
	}

	for(int i = 1; i <= n; i++){
		for(int w = 1; w <= W; w++){	
			// elemento pode fazer parte da solução
			if(wt[i - 1] <= w){
				// max...
				if((b[i - 1] + V[i - 1][w - wt[i - 1]]) > V[i - 1][w])
					V[i][w] = b[i - 1] + V[i - 1][w - wt[i - 1]];
				else
					V[i][w] = V[i - 1][w];
			}
			else
				V[i][w] = V[i - 1][w]; // wi > w
		}
	}

	// retorna o valor máximo colocado na mochila
	return V[n][W];
}

int main(int argc, char *argv[]){
	int testes;
	int carga_max; // capacidade máxima do canhão: W
	int N;	// número de projéteis disponiveis
	int R; // Resistencia do castelo

	cin >> testes;
	while(testes){		
		cin >> N;
		int danos[N];	// vetor com os valores (dano) de cada projetil
		int pesos[N];	// vetor com os pesos de cada prohetil
		int dano_max = 0;	// obtém o máximo de dano que o canhao pode fazer

		for(int i = 0; i < N; i++){
			cin >> danos[i];
			cin >> pesos[i];
		}
		cin >> carga_max;
		cin >> R;

		dano_max = knapsack(carga_max, pesos, danos, N);

		if(dano_max >= R)
			cout << "Missao completada com sucesso" << endl;
		else
			cout << "Falha na missao" << endl;
		testes--;
	}

	return 0;
}