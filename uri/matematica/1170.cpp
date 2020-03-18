//Blobs

#include <iostream>

using namespace std;

int main(){
	unsigned int N;
	double X;
	cin >> N;

	while(N--){
		int cont = 0;
		cin >> X;

		while(X > 1){
			X /= 2;
			cont++;
		}
		cout << cont << " dias" << endl;
	}
}