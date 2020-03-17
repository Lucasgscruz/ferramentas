// Flavious Josephus Legend
// Lista circular : desloca a cabeça para o final n vezes e depois remove
// Esse procedimento é feito até sobras apenas 1 elemento;
//fonte: https://www.youtube.com/watch?v=tdSLRndd4ZQ

#include <iostream>

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

	// mostra todos os elementos da lista
	void mostrar(){ 
		cout << "\nImprimindo todos os elementos...\n";
		No* c = cabeca;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else{
			do{ // percorre a lista
				cout << c->getId() << endl;
				c = c->getProx();
			}while(c and c != cabeca);
			cout << endl;
		}
	}

	// Executa problema de joseph
	int kill(int salto){
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
	int NC;
	cin >> NC;

	for(int caso = 1; caso <= NC; caso++){
		int n, k;
		cin >> n >> k;
		Lista l;

		for(int i = 1; i <= n; i++)
			l.inserir_final(i);

		int saida = l.kill(k);
		cout << "Case " << caso << ": " << saida << endl;
	}	
	return 0;
}