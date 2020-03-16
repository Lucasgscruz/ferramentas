// Even and Odd

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool funcEven(int& i, int& j){ 
	return (i < j);
}

bool funcOdd(int& i, int& j){
	return (i > j);	
}

int main(){
	int N;
	int aux;
	vector<int> evens;
	vector<int> odds;

	cin >> N;	
	while(N--){
		cin >> aux;
		if(aux % 2 == 0)
			evens.push_back(aux);
		else
			odds.push_back(aux);
	}

	sort(evens.begin(), evens.end(), funcEven);
	sort(odds.begin(), odds.end(), funcOdd);

	for(auto i: evens)
		cout << i << endl;

	for(auto i: odds)
		cout << i << endl;

	return 0;
}