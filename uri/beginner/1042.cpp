// SImple sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> vet;
	vector<int> vetSorted;
	int aux;

	while(cin >> aux){
		vetSorted.push_back(aux);
		vet.push_back(aux);
	}

	sort(vetSorted.begin(), vetSorted.end());

	for(auto i: vetSorted)
		cout << i << endl;
	cout << endl;

	for(auto i: vet)
		cout << i << endl;

	return 0;
}