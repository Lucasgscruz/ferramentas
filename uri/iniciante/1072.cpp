//Intervalo 2
#include <iostream>

using namespace std;

int main(){
	int N;
	int aux, in = 0, out = 0;

	cin >> N;

	while(N--){
		cin >> aux;
		if(aux < 10 or aux > 20)
			out++;
		else
			in++;
	}

	cout << in << " in" << endl;
	cout << out << " out" << endl;
	return 0;
}
