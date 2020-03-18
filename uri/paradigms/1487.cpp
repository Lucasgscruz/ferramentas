// Six flags, algoritmos guloso. Mochila multipla

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Brinquedo{
public:
	int D, P;
	double div;

	Brinquedo(int D, int P)
	{
		this->D = D; // duracao
		this->P = P; // pontuacao do brinquedo
		div = (double)P / D; // razao  pontuacao / duracao
	}

	bool operator<(Brinquedo const& a){
		return div > a.div;
	}
};


int main(int argc, char *argv[])
{
	int N, T, h = 1;

	while(true){
		vector<Brinquedo> brinquedos;

		cin >> N;
		cin >> T;

		if(N == 0)
			return 0;

		for(int i = 0; i < N; i++){
			int D, P;

			cin >> D;
			cin >> P;

			Brinquedo brinquedo(D, P);
			brinquedos.push_back(brinquedo);
		}

		sort(brinquedos.begin(), brinquedos.end());

		int pontuacao_total = 0, tempo_total = 0;

		for(int i=0; i < N; i++){
			int aux = T/brinquedos[i].D;
			pontuacao_total += aux * brinquedos[i].P;
			T -= aux * brinquedos[i].D;
		}
		
		// int i = 0;
		// while(i < N){
		// 	int aux_tempo_total = tempo_total + brinquedos[i].D;
		// 	if(aux_tempo_total <= T){
		// 		pontuacao_total += brinquedos[i].P;
		// 		tempo_total = aux_tempo_total;
		// 	}
		// 	else
		// 		i++;
			
		// }

		cout << "Instancia " << h++ << endl;
		cout << pontuacao_total << "\n\n";
	}

	return 0;
}
