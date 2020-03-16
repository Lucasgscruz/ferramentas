// Com problema no toolkit do site

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define fila queue
#define pilha vector

using namespace std;

int main(){
	int N;

	while(cin >> N and N){
		int A[N], aux;
		vector<int> saida;
		pilha<int> estacao;
		

		while(cin >> aux and aux){
			fila<int> B;
			B.push(aux);
			A[N-1] = N;
			for(int i = 1; i < N; i++){
				cin >> aux;
				B.push(aux);
				A[i-1] = i;
			}
			B.push(-1);

			for(auto i: A){
				if(i == B.front()){
					saida.push_back(i);
					B.pop();
				}
				else if(!estacao.empty() and B.front() == estacao.back()){
					saida.push_back(estacao.back());
					estacao.pop_back();
					B.pop();
				}
				else
					estacao.push_back(i);
			}

			for(int i = saida.size()-1; i < N; i++){
				if(estacao.back() == B.front()){
					saida.push_back(estacao.back());
					estacao.pop_back();
					B.pop();
				}
			}			

			// Se a estação ficar vazia ao final, todos os vagoes foram realocados
			if(B.front() == -1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;

			// Limpando saida e estacao
			saida.clear();
			estacao.clear();
		}
			cout << endl;

	}
	return 0;
}