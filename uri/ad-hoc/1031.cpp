/*Dancing Sentence
Adaptação do problema Flavious Josephus problem

*/

#include <iostream>
#define INF 1000000

using namespace std;

// classe No
class No{
private:
	int id;
	No* prox;
public:
	// construtor
	No(int id){
		this->id = id;
		this->prox = NULL;
	}

	int getId(){
		return this-> id;
	}

	No* getProx(){
		return prox;
	}

	void setProx(No* p){
		prox = p;
	}
};

// classe Lista
class Lista{
private:
	No* cabeca; // primeiro elemento
	No* cauda; // último elemento

public:
	Lista(){
		// se não passar elemento, então cabeca e cauda são NULL
		cabeca = NULL;
		cauda = NULL;
	}

	Lista(int id){
		// se passar elemento, então cria novo No
		cabeca = new No(id);
		cauda = cabeca;
	}

	// destrutor
	virtual ~Lista(){
		delete cabeca;
	}

	// verifica se a lista está vazia
	bool vazia(){
		return cabeca == NULL;
	}

	// insere no final (semelhante a push_back da list)
	void inserir_final(int id){
		No* novo_no = new No(id);

		if(vazia()){
			cabeca = novo_no;
			cauda = novo_no;
			cauda->setProx(cabeca);
		}
		else{
			cauda->setProx(novo_no);
			cauda = novo_no;
			cauda->setProx(cabeca);
		}
	}

	// Executa problema de joseph
	int kill(int salto){
		//Eliminando o 1 da lista
		cabeca = cabeca->getProx();
		cauda->setProx(cabeca);

		while(cabeca->getProx() != cabeca){	
			for(int i = 1; i <= salto-1; i++){
				cauda = cabeca;
				cabeca = cabeca->getProx();	
			}
			cabeca = cabeca->getProx();
			cauda->setProx(cabeca);
		}
		return cabeca->getId();
	}
};

int main(){
	int N;

	while(cin >> N and N){

		for(int m = 1; m < INF; m++){
			Lista l;
			for(int i = 1; i <= N; i++){
				l.inserir_final(i);
			}

			if(l.kill(m) == 13){
				cout << m << endl;
				break;
			}
		}
	}
	return 0;		
}