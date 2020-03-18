// Throwing Cards Away

#include <iostream>
#include <deque>

using namespace std;

int main(){
	int n = 0;
	deque<int> deck;
	deque<int> aux;

	cin >> n;

	while(n){

		for(int i = 1; i <= n; i++)
			deck.push_back(i);

		while(deck.size() > 1){
			aux.push_back(deck.front());
			deck.pop_front();
			deck.push_back(deck.front());
			deck.pop_front();
		}

		cout << "Discarded cards: ";
		int size = aux.size();
		for(int i = 0; i < size; i++){
			if(i == size - 1){
				cout << aux[i] << endl;
				break;
			}
			cout << aux[i] << ", ";
		}
		cout << "Remaining card: " << deck.front() << endl;

		cin >> n;
		deck.clear();
		aux.clear();
	}
	return 0;
}