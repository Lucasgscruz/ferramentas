// the greatest

#include <iostream>
#define abs(A, B) ((A - B < 0) ? ((A + B + (A - B) * -1) / 2) : (A + B + (A - B)) / 2)
using namespace std;

int main(){
	int a, b, c, aux;
	cin >> a;
	cin >> b;
	cin >> c;

	aux = abs(a, b);
	cout << abs(c,aux)<< " eh o maior" << endl;
	return 0;
}