//Sphere
#include <iostream>
#define PI 3.14159

using namespace std;

int main(){
	double radius;
	cin >> radius;

	cout << fixed;
	cout.precision(3);
	cout << "VOLUME = " << (4.0/3) * PI * (radius* radius * radius) << endl;
	
	return 0;
}
