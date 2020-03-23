// Simple Base Conversion
// dec to hex

#include <iostream>

using namespace std;

int main(){
	string input;
	int a = 0xF;
	
	while(cin >> input and input != "-1"){
		if(input[1] == 'x')
			cout << dec << stoul(input, nullptr, 16) << endl;
		else{
			printf("0x");
			printf("%lX\n", stoul(input));
		}
	}
	return 0;
}