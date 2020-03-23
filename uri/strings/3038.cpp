#include <iostream>
#include <map>
using namespace std;

int main(){
	map <char,char> table = {{'@', 'a'}, {'&', 'e'}, {'!', 'i'}, {'*', 'o'}, {'#', 'u'}};
	string input;

	while(getline(cin, input)){
		for(auto i: input){
			if(!table[i])
				cout << i;
			else
				cout << table[i];
		}
		cout << endl;
	}
	
	return 0;
}