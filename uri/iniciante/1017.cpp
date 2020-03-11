#include <iostream>
 
using namespace std;
 
int main() {
 
	int time, speed;
	cin >> time;
	cin >> speed;

	cout << fixed;
	cout.precision(3);
	cout << time * speed / 12.0 << endl;
	
    return 0;
}