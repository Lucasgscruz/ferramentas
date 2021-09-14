#include <iostream>
#include <string>

using namespace std;

int main()
{
	char simbol;

	while(!cin.eof())
	{
		cin.get(simbol);
		cout << simbol;
	}
	return 0;
}