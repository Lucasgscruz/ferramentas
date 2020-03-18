//Area
#include <iostream>
#define PI 3.14159

using namespace std;

int main(){
	double a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	cout << fixed;
	cout.precision(3);
	cout << "TRIANGULO: " << a * c / 2 << endl;
	cout << "CIRCULO: " << PI * (c * c) << endl;
	cout << "TRAPEZIO: " << ((a + b) * c) / 2<< endl;
	cout << "QUADRADO: " << b * b << endl;
	cout << "RETANGULO: " << a * b << endl;
	return 0;
}