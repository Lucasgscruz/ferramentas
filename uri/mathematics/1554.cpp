// N.1 Continuous

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define abs(x) ((x < 0) ? -x : x)

using namespace std;

struct point{
	int x,y;
};

bool compare(pair<short, double>& a, pair<short, double>& b){
	return a.second < b.second;
}

int main(){
	unsigned int C;
	cin >> C;

	while(C--){
		short N;
		point white;
		point ball;
		vector<pair<short, double>> distances;

		cin >> N;
		cin >> white.x >> white.y;

		for(short i = 1; i <= N; i++){
			point ball;
			cin >> ball.x >> ball.y;

			double result = sqrt(pow(ball.x - white.x, 2) + pow(ball.y - white.y, 2)); // distance between 2 points

			distances.push_back(make_pair(i, result));			
		}

		sort(distances.begin(), distances.end(), compare);

		cout << distances.front().first << endl;
	}
	return 0;
}