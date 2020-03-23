//Deciphering the Encrypted Card
#include <iostream>
#include <map>

using namespace std;

int main(){
	int C, N;
	string cipher1, cipher2, phrase;
	

	while(cin >> C >> N){
		getline(cin, cipher1); // consume \n
		getline(cin, cipher1);
		getline(cin, cipher2);
		
		map<char, char> table;
		for(int i = 0; i < C; i++){
			table[cipher1[i]] = cipher2[i];
			table[cipher2[i]] = cipher1[i];
		}
		while(N--){
			getline(cin, phrase);
			for(auto i: phrase){
				char aux = toupper(i);
				if(table[toupper(i)]){
					if(islower(i)){
						aux = tolower(table[aux]);
						cout << aux;
					}
					else if(isalpha(i))
						cout << table[aux];
					else{
						aux = tolower(table[aux]);
						cout << aux;
					}
				}
				else{
					cout << i;
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}