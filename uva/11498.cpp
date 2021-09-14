#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int k, n, m;

	while(cin >> k)
	{	
		int x, y;
		cin >> n >> m;
		
		while(k--)
		{
			cin >> x >> y;

			if(x == n || y == m)
				cout << "divisa" << endl;
			else if(y < m)
			{
				if(x > n)
					cout << "SE" << endl;
				if(x < n) 
					cout << "SO" << endl;
			}
			else if(y > m)
			{
				if(x > n)
					cout << "NE" << endl;
				if(x < n) 
					cout << "NO" << endl;
			}
		}
	}
	return 0;
}