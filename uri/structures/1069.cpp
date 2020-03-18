// Diamonts and Sand
// Balaceamento de parenteses. Pilha

#include <iostream>
#include <stack>

using namespace std;

int main(){
	unsigned int N;
	cin >> N;

	while(N--){
		int cont = 0;
		string mine;
		stack<char> diamonts;
		
		cin >> mine;

		for(auto i: mine){
			if(i == '<'){
				diamonts.push(i);
			}
			else if(i == '>'){
				if(!diamonts.empty()){
					diamonts.pop();
					cont++;
				}			
			}
		}

		cout << cont << endl;
	}
	return 0;
}