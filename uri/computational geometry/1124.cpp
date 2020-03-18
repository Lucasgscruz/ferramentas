// Elevador

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int L, C, R1, R2;
	
	while(cin >> L >> C >> R1 >> R2 && (L || C || R1 || R2)){
		int minDim = (L < C) ? (L) : (C);
		int maxRaio = (R1 > R2) ? (2 * R1) : (2 * R2);

		if(minDim < maxRaio){
			cout << "N" << endl;
			continue;
		}

		int R = R1 + R2;
		// Criar dois pontos diagonais representando o centro das circunferencias
		pair <int, int> p1 = make_pair(R1, L - R1);
		pair <int, int> p2 = make_pair(C - R2, R2);
		int R_linha = sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));

		// Se r_linha for menor que R significa que os cilindros nao cabem no elevador
		if(R_linha >= R)
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}
	return 0;
}