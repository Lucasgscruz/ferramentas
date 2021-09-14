#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int t, in;
	map<int, int> salary;

	cin >> t;

	for(int i = 1; i <= t; ++i)
	{
		cin >> in;
		salary[in] = in;

		cin >> in;
		salary[in] = in;

		cin >> in;
		salary[in] = in;

		int j = 0;
		for(auto& valor: salary)
		{	
			if (j == 1){
				cout << "Case " << i << ": "<< valor.first << endl;
				break;
			}
			++j;
		}
		salary.clear();
	}
	return 0;
}