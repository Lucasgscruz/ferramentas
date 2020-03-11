#include <iostream>

using namespace std;

int main(){
	string palavra;
	
	getline(cin, palavra);
	int N = stoi(palavra);

	for(int i = 0; i < N; i++){
		getline(cin, palavra);	
		int tam = palavra.size();
		int tam2 = tam/2;

		for(int i = tam2-1; i >= 0; i--)
			cout << palavra[i];
		for(int i = tam-1; i >= tam2; i--)
			cout << palavra[i];
		cout << endl;
	}
	
	return 0;
}