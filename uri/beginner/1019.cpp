// Time conversion

#include <iostream>
using namespace std;


int main(){
	int N, hora[3];
	cin >> N;

	hora[0] = N / 60 / 60;
	hora[1] = (N - (hora[0] * 60 * 60)) / 60;
	hora[2] = N - (hora[0] * 60 * 60) - (hora[1] * 60);

	cout << hora[0] << ":" << hora[1] << ":" << hora[2] << endl;

	return 0;
}