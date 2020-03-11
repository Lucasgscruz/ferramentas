#include <iostream>
#define PI 3.14159

using namespace std;

int main(){
	double raio;
	cin >> raio;

	cout << fixed;
	cout.precision(4);
	cout << "A=" << PI * (raio * raio) << endl;
	return 0;
}