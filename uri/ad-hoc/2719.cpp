#include <iostream>
#include <vector>

using namespace std;

int main(){
	unsigned int T;
	cin >> T;
	while(T--){
		int N, M, trips = 0;
		vector<int> p;
		cin >> N >> M;
		
		while(N--){
			int aux;
			cin >> aux;
			p.push_back(aux);
		}

		int weight = 0;
		for(auto i: p){
			weight += i;
			if(weight <= M)
				continue;
			else{
				trips++;
				weight = i;
			}
		}
		trips++;
		cout << trips << endl;
	}
	return 0;
}