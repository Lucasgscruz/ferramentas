// Aritmética primária

#include <iostream>
#include <string>

using namespace std;

void completa(string& a, string& b){
	int tamA = a.size();
	int tamB = b.size();

	if(tamA == tamB)
		return;
	else if(tamA < tamB){
		int dif = tamB - tamA;
		for(int i = 0; i < dif; i++)
			a.insert(0, "0");
	}
	else if(tamB < tamA){
		int dif = tamA - tamB;
		for(int i = 0; i < dif; i++)
			b.insert(0, "0");
	}
}

int main(){
	unsigned int a, b;
	int cont;

	while(cin >> a >> b && (a || b)){
		string str_a, str_b;
		str_a = to_string(a);
		str_b = to_string(b);
		cont = 0;

		completa(str_a, str_b); // completa com 0 caso os numeros tenham temanhos diferentes
		int carry = 0;

		while(!str_a.empty()){
			string n1, n2;
			n1.push_back(str_a.back());
			n2.push_back(str_b.back());
			if(stoi(n1) + stoi(n2) + carry > 9){
				carry = 1;
				cont++;
			}
			else
				carry = 0;

			str_a.pop_back(); 
			str_b.pop_back();
		}


		if(!cont)
			cout << "No carry operation." << endl;
		else if(cont == 1)
			cout << "1 carry operation." << endl;
		else
			cout << cont << " carry operations." << endl;
	}
	return 0;
}