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
void In2Pos(vector<string>& expr){
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
	      cout << c;
	    }
	    else if(c == "("){
	    	pilha.push("(");
	    }
	    else if(c == ")" || c == "$"){
	    	do{
	        	t = pilha.top();
	        	pilha.pop();
	        	if(t != "("){
	          		cout << t;
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
	        		cout << t;
	        	}
	        }
	    }
	}
	cout << endl;
}


int main(){
	int N;
	string ler;
	cin >> N;

	while(N){
		vector<string> expr;
		string aux = "";
		cin >> ler;
		int tam = ler.size();

		for(char i: ler){
			if(i == '+' || i == '-' || i == '*' || i == '/' || i == '^' || i == '(' || i == ')'){
				if(aux.size() > 0){
					expr.push_back(aux);
					aux.clear();
					aux += i;
					expr.push_back(aux);
					aux.clear();
				}
				else{
					aux += i;
					expr.push_back(aux);
					aux.clear();
				}
			}
			else{
				aux += i;
			}
		}
		if(aux.size() > 0){
			expr.push_back(aux);
			aux.clear();
		}

		In2Pos(expr);		
		N--;
	}
	
	return 0;
}