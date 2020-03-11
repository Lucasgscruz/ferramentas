// Simple Factorial
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int n;
	int total = 1;
	cin >> n;

	while( n >= 1)
		total *= n--;

	cout << total << endl;
	return 0;
}