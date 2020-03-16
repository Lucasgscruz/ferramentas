/*** 
* PROBLEMA 2
* 
* Seja 'l' uma lista de inteiros ordenados de tamanho 1M, e 'v' um valor inteiro
* determine se o valor v existe ou não nessa lista utilizado no máximo 20 comparações.
* Faça uma função que imprima no console o número de comparações utilizadas e se o 
* o valor v foi ou não encontrado na lista.
*/

#include <iostream>

using namespace std;

pair<bool, int> buscaBinaria(int* vet, int chave, int tam){
     int inf = 0;     // limite inferior (o primeiro índice de vetor eh 0)
     int sup = tam-1; // limite superior (termina em um número a menos. 0 a 9 são 10 números)
     int meio;
     int cont = 0; // contador de comparações

    while(inf <= sup){
        meio = (inf + sup)/2;
        if(chave == vet[meio])
            return make_pair(true, cont);
        if(chave < vet[meio])
            sup = meio - 1;
        else
            inf = meio+1;

        cont++;          
    }

    return make_pair(false, cont);   // não encontrado
}

int main(){
	int vet[1000000], chave = 5349;
	pair<bool, int> saida;

	for(int i = 0; i < 1000000; i++)
		vet[i] = i;

	saida = buscaBinaria(vet, chave, sizeof(vet)/sizeof(int));

	if(saida.first)
		cout << "O número " << chave << " está presente na lista\n" << "Foram realizadas " << saida.second << " comparações\n";
	else
		cout << "O número " << chave << " não está presente na lista\n";
	return 0;
}