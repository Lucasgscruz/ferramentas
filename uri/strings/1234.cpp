//Dancing Sentence

#include <iostream>

using namespace std;

int main(){
	string sentence;
	while(getline(cin, sentence)){
		int i = 0, tam = sentence.size();
		while(isspace(sentence[i])){
			cout << " ";
			i++;
		}

		bool up = true;

		for(; i < tam; i++){
			if(isspace(sentence[i]))
				cout << " ";
			else if(up){
				putchar(toupper(sentence[i]));
				up = false;
			}
			else{
				putchar(tolower(sentence[i]));
				up = true;	
			}
		}
		cout << endl;
	}

	return 0;
}