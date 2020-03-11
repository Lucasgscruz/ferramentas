// Matriz 123

#include <iostream>

using namespace std;

int main(){
	int N;

	while(cin >> N){
		int j1 = 0, j2 = N - 1;
	
		for(int i = 0; i  < N; i++){
			for(int j = 0; j < N; j++){
				if(j != j1 and j != j2)
					cout << "3";
				else
					(j == j2) ? cout << "2" : cout << "1";
			}
			j1++;
			j2--;
			cout << endl;
		}
	}
	return 0;
}
