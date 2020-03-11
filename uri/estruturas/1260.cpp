// Hardwood Species

#include <iostream>
#include <map>

using namespace std;

void calcula(map<string, int>& floresta){
	int total = 0;
	
	for(pair<string, int> i: floresta)
		total += i.second;

	cout << fixed;
	cout.precision(4);

	for(pair<string, int> i: floresta){
		cout << i.first << " " << (double)i.second/total * 100 << endl;
	}
}

int main(){
	string arvore;
	getline(cin, arvore);
	getline(cin, arvore);
	
	while(true){
		map<string, int> floresta;
		while(cin.good()){
			getline(cin, arvore);	
			if(arvore == "") break;
			floresta[arvore] += 1;
		}

		calcula(floresta);

		if(!cin.good())
			break;
		cout << endl;
	}

	return 0;
}