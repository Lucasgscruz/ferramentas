// Revisão de Contrato

#include <iostream>
#include <string>

using namespace std;

int main(){
	string digito, valor, aux;

	while(cin >> digito >> valor && (stoi(digito) || stol(valor))){
		int tam = valor.size();
		aux = "";
		for(int i = 0; i < tam; i++){
			if(valor[i] != digito.c_str()[0])
				aux += valor[i];
		}

		tam = aux.size();
		int cont = 0;

		for(int i = 0; aux[i] == '0'; i++) cont++;

		if(cont > 0)
			aux.erase(0, cont);

		if(aux.empty()){
			cout << "0" << endl;
			continue;
		}

		cout << aux << endl;		
	}
	return 0;
}