/*** 
* PROBLEMA 4
* É uma variante do problema 3 e sua resposta contempla resultado para as duas questões.
* 
*
* Seja 'm' uma string que representa uma expressão matemática envolvendo os operadores 
* '+', '-', '*' , '/', '(' e ')' construa uma função que determina o resultado da expressão.
* exemplo: 5 + 4 * (3 + 2) = 25
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//Funcao auxiliar para definir maior prioridade entre dois simbolos
int prioridade(string c, string t){
	int pc,pt;

	if(c == "^")
		pc = 4;
	else if(c == "*" || c == "/")
		pc = 2;
	else if(c == "+" || c == "-")
		pc = 1;
	else if(c == "(")
		pc = 4;

	if(t == "^")
		pt = 3;
	else if(t == "*" || t == "/")
		pt = 2;
	else if(t == "+" || t == "-")
		pt = 1;
	else if(t == "(")
		pt = 0;

	return (pc > pt);
}

// Converte expressao do fromato infixa para posfixa
vector<string> In2Pos(vector<string>& expr){
	vector<string> exprPos;
	stack<string> pilha;
	int i = 0, tamExpr = expr.size();
	string t;

	expr.push_back("$"); // Marca o final da expressao	
	pilha.push("(");
	 
	for(string c: expr){
	    c = expr[i];
	    i++;
	    if(isalnum(c[0])){
	      // cout << c;
	    	exprPos.push_back(c);
	    }
	    else if(c == "("){
	    	pilha.push("(");
	    }
	    else if(c == ")" || c == "$"){
	    	do{
	        	t = pilha.top();
	        	pilha.pop();
	        	if(t != "("){
	          		// cout << t;
	          		exprPos.push_back(t);
	        	}
	      	}while(t != "(");
	    }
	    else if(c == "+" || c == "-" || c == "*" || c == "/" || c == "^" ){
	      	while(true){
	      		t = pilha.top();
	      		pilha.pop();
	        	if(prioridade(c,t)){
	        		pilha.push(t);
	        		pilha.push(c);
	        		break;
	        	}
	        	else{
	        		// cout << t;
	        		exprPos.push_back(t);
	        	}
	        }
	    }
	}
	return exprPos;
}

double calculaPos(vector<string> pos){
	int total = 0;
	stack<double> pilha;

	for(auto i: pos){
		if(i == "+"){
			double a = pilha.top();
			pilha.pop();
			double b = pilha.top();
			pilha.pop();

			a = a + b;
			pilha.push(a);

		} else if (i == "-"){
			double a = pilha.top();
			pilha.pop();
			double b = pilha.top();
			pilha.pop();

			a = a - b;
			pilha.push(a);

		} else if(i == "*"){
			double a = pilha.top();
			pilha.pop();
			double b = pilha.top();
			pilha.pop();

			a = a * b;
			pilha.push(a);

		} else if(i == "/"){
			double a = pilha.top();
			pilha.pop();
			double b = pilha.top();
			pilha.pop();

			a = a / b;
			pilha.push(a);
		}
		else
			pilha.push(stod(i));
	}

	return pilha.top();
}

int main(){	
	string ler;
	vector<string> inFixa;
	vector<string> posFixa;
	string aux = "";
	
	while(cin >> ler)
		inFixa.push_back(ler);

	posFixa = In2Pos(inFixa);

	inFixa.pop_back();
	for(auto i: inFixa)
		cout << i << " ";

	cout << "= " << calculaPos(posFixa) << endl;
	
	return 0;
}