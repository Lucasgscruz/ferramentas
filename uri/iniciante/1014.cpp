#include <iostream>
using namespace std;

int main(){
	int distance;
	float fuel;

	cin >> distance;
	cin >> fuel;
	cout << fixed;
	cout.precision(3);

	cout << distance/fuel << " km/l" << endl;
	return 0;
}