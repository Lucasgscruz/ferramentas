#include <iostream>

using namespace std;

int main(){
	int h1, m1, h2, m2;
	while(cin >> h1 >> m1 >> h2 >> m2){
		if(!h1 and !m1 and !h2 and !m2){
			// cout << endl;
			break;
		}

		int min1, min2;

		min1 = (h1 * 60) + m1;

		if(h1 > h2){
			h2 += 24;
		}
		else if(h1 == h2 and m1 >= m2){
			h2 += 24;
		}

		min2 = (h2 * 60) + m2;

		cout << min2 - min1 << endl;
	}
	return 0;
}