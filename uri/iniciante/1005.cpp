#include <iostream>

using namespace std;

int main(){
	float a = 0, b = 0;
	cin >> a;
	cin >> b;

	cout.precision(5);
	cout << fixed;
	cout << "MEDIA = " << ((3.5 * a) + (7.5 * b))/(3.5+7.5) << endl;
	return 0;
}