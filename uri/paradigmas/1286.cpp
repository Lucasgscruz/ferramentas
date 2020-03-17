// Motoboy- Problema foi reduzido ao problema da mochila
// Problema da mochila - Programação dinamica

#include <iostream>

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
	int orders; // número de pedidos recebidos por Roberto
	int pizza_max; // numero máximo deo pizzas a seres entregues W

	while(cin >> orders and orders){		
		cin >> pizza_max;   
		int times[orders];	// vetor com os tempos de entrega de cada pedido
		int pizzas[orders];	// vetor com o numero de pizzas de cada pedido
		int tempoFinal = 0;

		for(int i = 0; i < orders; i++){
			cin >> times[i];
			cin >> pizzas[i];
		}
		
		tempoFinal = knapsack(pizza_max, pizzas, times, orders);

		cout << tempoFinal << " min." << endl;
	}

	return 0;
}