// DDD

#include <iostream>
#include <map>

using namespace std;

int main(){
	unsigned int DDD;
	map<int, string> catalog;

	catalog[61] = "Brasilia";
	catalog[71] = "Salvador";
	catalog[11] = "Sao Paulo";
	catalog[21] = "Rio de Janeiro";
	catalog[32] = "Juiz de Fora";
	catalog[19] = "Campinas";
	catalog[27] = "Vitoria";
	catalog[31] = "Belo Horizonte";

	cin >> DDD;

	if(catalog[DDD] == "")
		cout << "DDD nao cadastrado" << endl;
	else
		cout << catalog[DDD] << endl;

	return 0;
}