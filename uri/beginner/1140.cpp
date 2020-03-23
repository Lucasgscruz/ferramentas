// Flowers Flourish from France

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
	string input;

	while(getline(cin, input)){
		if(input == "*") break;
		
		vector<string> words;
		istringstream tokens{input};

		while(tokens >> input)
			words.push_back(input);

		char first = words[0][0];
		bool tautogram = true;

		for(auto i: words){
			if(i[0] != toupper(first) and i[0] != tolower(first)){
				tautogram = false;
				break;
			}
		}

		(tautogram) ? cout << "Y\n" : cout << "N\n";
	}
	return 0;
}