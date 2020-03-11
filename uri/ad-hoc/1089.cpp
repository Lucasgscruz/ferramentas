//Loop musical

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;

	cin >> n;
	while(n){
		vector<float> wave(n);
		vector<char> compare;

		for(int i = 0; i < n; i++)
			cin >> wave[i];
		wave.push_back(wave[0]);
		wave.push_back(wave[1]);

		int size = wave.size();

		for(int i = 1; i < size; i++){
			if(wave[i] > wave[i-1])
				compare.push_back('>');
			else
				compare.push_back('<');
		}
 		
 		int cont = 0;
 		size = compare.size();

		for(int i = 1; i < size; i++){
			if(compare[i] != compare[i-1])
				cont++;
		}

		cout << cont << endl;
		cin >> n;
	}
	return 0;
}
