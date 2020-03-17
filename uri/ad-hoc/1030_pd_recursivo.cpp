// fonte: https://pt.stackoverflow.com/questions/54982/problema-de-josephus-recursivo
#include <iostream>

using namespace std;

int f(int n, int k){
    if(n==1)
    	return 1;
    return (((f(n - 1, k) + k-1) % n) + 1);   
}

int main(){
	unsigned int NC;
	cin >> NC;

	for(int i = 1; i <= NC; i++){
		unsigned int n, k;
    	cin >> n >> k;
    	cout << "Case " << i << ": " << f(n, k) << endl;
	}
    return 0;
}