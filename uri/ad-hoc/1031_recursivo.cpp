/*Dancing Sentence
Adaptação do problema Flavious Josephus problem

*/

#include <iostream>
#define INF 1000000

using namespace std;

int f(int n, int k){
    if(n==1)
    	return 1;
    return (((f(n - 1, k) + k-1) % n) + 1);   
}

int main(){
	int N;

	while(cin >> N and N){
		for(int m = 1; m < INF; m++){
			if(f(N-1, m)+1 == 13){
				cout << m << endl;
				break;
			}
		}
	}
	return 0;		
}