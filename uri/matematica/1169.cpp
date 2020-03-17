// truncar double

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int N;
	cin >> N;

	while(N--){
		int X;
		double sum=1;
		unsigned long long int truncar;

		cin >> X;
		sum = pow(2, X)/12/1000;
		truncar = sum;
		cout << truncar << " kg" << endl;
	}
	return 0;
}