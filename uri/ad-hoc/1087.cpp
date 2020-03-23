#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int x1, y1, x2, y2;
	int leaps;

	while(cin >> x1 >> y1 >> x2 >> y2 and (x1 or y1 or x2 or y2)){
		if(x1 == x2 and y1 == y2)
			leaps = 0;
		else if(x1 == x2 or y1 == y2)
			leaps = 1;
		else if(abs(x1 - x2) == abs(y1 - y2))
			leaps = 1;
		else
			leaps = 2;

		cout << leaps << endl;
	}
	return 0;
}