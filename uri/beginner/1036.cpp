// Raizes da formula de baskara

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	double a, b, c, delta = 0.0;

	cin >> a >> b >> c;

	delta = pow(b, 2) - (4 * a *c);

	if(delta < 0 || a == 0){
		cout << "Impossivel calcular\n";
		return 0;
	}

	cout << fixed;
	cout.precision(5);
	cout << "R1 = "<< (-b + sqrt(delta)) / (2 * a) << endl;
	cout << "R2 = "<< (-b - sqrt(delta)) / (2 * a) << endl;
	return 0;
}