#include <iostream>

using namespace std;

int main(){
	float a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	cout << fixed;
	cout.precision(1);
	cout << "MEDIA = " <<((2 * a) + (3 * b) + (5 * c))/(2 + 3 + 5) << endl;
	return 0;
}