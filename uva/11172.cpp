#include <iostream>

using namespace std;

int main()
{
	int iter,a,b;
	cin >> iter;

	while(iter--)
	{
		cin >> a >> b;
		if (a > b) cout << ">" << endl;
		else if (b > a) cout << "<" << endl;
		else cout << "=" << endl;
	}
	return 0;
}