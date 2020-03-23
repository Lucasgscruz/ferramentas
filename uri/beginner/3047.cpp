#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int monica, f1, f2, f3;
	vector<int> children;

	cin >> monica >> f1 >> f2;
	children.push_back(f1);
	children.push_back(f2);
	f3 = monica - f1 - f2;
	children.push_back(f3);

	sort(children.begin(), children.end());
	cout << children.back() << endl;
	return 0;
}