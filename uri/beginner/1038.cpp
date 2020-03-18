#include <iostream>

using namespace std;

int main(){
	float tabela[] = {4.0, 4.50, 5.0, 2.0, 1.5};
	int a, b;
	cin >> a >> b;

	cout << fixed;
	cout.precision(2);
	cout << "Total: R$ " << tabela[a-1] * b << endl ;
	return 0;
}