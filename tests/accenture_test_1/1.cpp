// Transformar numeros romanos em hindu-arabicos
/***
    PROBLEMA 1

    Dada uma string representando um numero em algarismos romanos, converte-la
    para um inteiro convencional.

    Considere somente numeros cuja saida correspondente seja menor ou igual a
    3999.

    Observacao: a representacao da entrada sera sempre em letras maiusculas.

    Seguem os valores de cada algarismo romano:
    * I = 1
    * V = 5
    * X = 10
    * L = 50
    * C = 100
    * D = 500
    * M = 1000

    Exemplos:
    1. "I" -> 1
    2. "III" -> 3
    3. "XVII" -> 17
    4. "CMXCII" -> 992
    5. "MMMCIV" -> 3104
***/

#include <iostream>
#include <sstream>

using namespace std;

int problema1(string romano){
	
	char Rom[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int valor[] = {1,5,10,50,100,500,1000};
	int soma = 0;
	int anterior = 0;		
	char letra = ' ';
			
	for(int i = 0; i < romano.size(); i++){
		letra = romano[i];
		int tam = sizeof(Rom)/sizeof(char);
		for(int j = 0; j < tam; j++) {
			if(letra == Rom[j]) {
				soma = soma + valor[j];
				if(anterior < valor[j]) {
					soma = soma - anterior * 2;
				}
				anterior = valor[j];
			}
		}
	}
    return soma;
}

int main(){
	string roman;
	cout << "Digite o número romano: ";
	cin >> roman;
	cout << problema1(roman) << endl;

	return 0;
}