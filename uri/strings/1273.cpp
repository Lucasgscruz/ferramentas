// Justificador

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int N = 0;
	string palavra;
	cin >> N;

	while(N){
		vector<string> words;
		int maxTam = 0;
		
		for(int i = 0; i < N; i++) {
			cin >> palavra;
			words.push_back(palavra);

			if(palavra.size() > maxTam)
				maxTam = palavra.size();
		}

		int tam = words.size();

		for(int i = 0; i < tam; i++){
			int diferenca = maxTam - words[i].size();
			for(int j = 0; j < diferenca; j++)
				cout << " ";
			cout << words[i] << endl;
		}

		cin >> N;
		if(N)
			cout << endl;
	}
	return 0;
}