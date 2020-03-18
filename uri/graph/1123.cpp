#include <iostream>
#include <queue>
#include <list>
#define INFINITO 10000007

using namespace std;

class Grafo{
private:
	int V;  
	int destino;
	int** matriz; 
	list<pair<int, int> >* adj; 
public:
	// construtor
	Grafo(int V, int C){
		this-> V = V; 
		this-> destino = C-1;
		this-> matriz = new int*[V];
		for(int i = 0; i < V; i++){
			matriz[i] = new int[V];
			for(int j = 0; j < V; j++)
				matriz[i][j] = 0;
		}

		this-> adj = new list<pair<int, int> >[V]; // cria o array com as listas de adj (peso, id)
	}

	// adiciona uma aresta ao grafo de v1 à v2
	void addAresta(int v1, int v2, int custo){
		adj[v1].push_back(make_pair(v2, custo));
		adj[v2].push_back(make_pair(v1, custo));
		matriz[v1][v2] = custo;
		matriz[v2][v1] = custo;
	}

	int dijkstra(int orig){
		int dist[V]; // vetor de distâncias
		bool visitados[V]; // vetor de visitados
		bool rota[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++){
			dist[i] = INFINITO;
			visitados[i] = false;
			if(i <= destino)
				rota[i] = true;
			else
				rota[i] = false;
		}

		dist[orig] = 0; // a distância de orig para orig é 0

		pq.push(make_pair(dist[orig], orig));  // insere o vertice origem na fila de prioridade

		// loop do algoritmo
		while(!pq.empty()){
			pair<int, int> p = pq.top(); // extrai o pair do topo da fila de prioridade
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			
			if(visitados[u] == false){ // verifica se o vértice não foi expandido
				
				visitados[u] = true; // marca como visitado
				for(auto it: adj[u]){
					int v = it.first;
					int custo_aresta = it.second;
					if(dist[v] > (dist[u] + custo_aresta)){
						dist[v] = dist[u] + custo_aresta;
						if(!rota[v])
							pq.push(make_pair(dist[v], v));
					}
				}			
			}
		}

		for(int i = 0; i <= destino; i++){
			if(dist[i+1] > dist[i] + matriz[i][i+1])
				dist[i+1] = dist[i] + matriz[i][i+1];
		}

		return dist[destino];
	}
};

int main(){
	int N, M, C, K;

	while(cin >> N >> M >> C >> K && (N || M || C || K)){
		Grafo grafo(N, C); // cria o grafo

		for(int i = 0, v1, v2, pedagio; i < M; i++){
			cin >> v1 >> v2 >> pedagio;
			grafo.addAresta(v1, v2, pedagio);
		}

		cout << grafo.dijkstra(K) << endl;
	}
	
	return 0;
}