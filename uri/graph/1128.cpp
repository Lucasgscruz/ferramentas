/*
Problema resolvido pelo algotimo de Kosaraju o qual verifica componetes fortemente conexas.

N = numero tersecções (2 ≤ N ≤ 2000)
M = número de ruas (2 ≤ M ≤ N(N−1)/2)
V = vertice origem   (1 ≤ V, W ≤ N , V ≠ W )
W = vertice destino  (1 ≤ V, W ≤ N , V ≠ W )
P = {1,2} / 1-mão única, 2-mão dupla

Aceito = 858º

*/

#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Grafo{
private:
	int V;   // número de vértices
	list<int>* adj; // ponteiro para um array contendo as listas de adjacências


	void preenche(int v, bool* visitados, stack<int>& pilha){
		// marca o vértice atual como visitado
		visitados[v] = true;

		// percorre os adjacentes de v
		for(int i: adj[v]){
			if(visitados[i] == false)
				preenche(i, visitados, pilha);
		}
		pilha.push(v);
	}

	// bem parecida com a função preenche
	void DFS(int v, bool* visitados){
		// marca o vértice atual como visitado
		visitados[v] = true;

		// percorre os adjacentes de v
		for(int i: adj[v]){
			if(visitados[i] == false)
				DFS(i, visitados);
		}
	}
	
public:	
	// construtor
	Grafo(int N){
		this-> V = N; // atribui o número de vértices
		this-> adj = new list<int>[V]; // cria o array com as listas de adj (peso, id)
	}

	// adiciona uma aresta ao grafo de v1 a v2
	void addAresta(int v1, int v2, int flag){
		v1--;
		v2--; // Operaçao para colocar os indices comecando de zero
		if(flag == 1){
			adj[v1].push_back(v2);
		}
		else{			
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
	}

	// obtém o grafo transposto
	Grafo obterGrafoTransposto(){
		Grafo grafo_transposto(V);

		for(int v = 0; v < V; v++){
			list<int>::iterator i;
			for(int i: adj[v]){
				// insere no novo grafo
				grafo_transposto.adj[i].push_back(v);
			}
		}

		return grafo_transposto;
	}

	// Obtém o numero componentes fortemente conexas do grafo
	int obterComponentes(){
		stack<int> pilha;
		bool* visitados = new bool[V];
		int cont = 0;

		// marca todos como não visitados
		for(int i = 0; i < V; i++)
			visitados[i] = false;

		// preenche a pilha
		for(int i = 0; i < V; i++){
			if(visitados[i] == false)
				preenche(i, visitados, pilha);
		}

		// cria o grafo transposto
		Grafo gt = obterGrafoTransposto();

		// marca todos como não visitados novamente
		for(int i = 0; i < V; i++)
			visitados[i] = false;

		// processa os vértices de acordo com a pilha
		while(!pilha.empty()){
			// obtém o elemento do topo
			int v = pilha.top();

			//remove o elemento
			pilha.pop();

			// imprime cada componente fortemente conexa
			if(visitados[v] == false){
				cont++;
				gt.DFS(v, visitados);
			}
		}
		return cont;
	}
};

int main(){
	int N, M;

	while(cin >> N >> M && (N || M)){
		Grafo grafo(N); // cria o grafo

		for(int i = 0, V, W, P; i < M; i++){
			cin >> V >> W >> P;
			grafo.addAresta(V, W, P);
		}

		if(grafo.obterComponentes() == 1) // O grafo deve possuir apenas 1 componente fortemente conexa
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}