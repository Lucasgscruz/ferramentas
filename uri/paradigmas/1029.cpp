// Fibonacci, Quantas Chamadas?

#include <iostream>
#include <math.h>
using namespace std;

int fib(int num = -1){
	static int i = 0;

	if(num == -1){
		int aux = i;
		i = 0;
		return --aux;
	}
	
	i++;

	if(num == 0)
		return 0;
	else if(num == 1)
		return 1;
	return fib(num - 1) + fib(num - 2);
}

int main(){
	int val = 0, N = 0;
	cin >> N;
	while(N){
		int res = 0, calls = 0;
		cin >> val;

		res = fib(val);
		calls = fib();
		
		cout << "fib("<< val << ") = "<< calls << " calls = " << res << endl;
		N--;
	}
	return 0;
}

