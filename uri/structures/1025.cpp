// Where is the Marble?

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    unsigned int N, Q, test = 1;
    while(cin >> N >> Q and (N or Q)){
        vector<unsigned int> marbles(N);
        vector<unsigned int> queries(Q);

        for(int i = 0; i < N; i++)
        	cin >> marbles[i];

        sort(marbles.begin(), marbles.end());

        for(int i = 0; i < Q; i++)
        	cin >> queries[i];

        cout << "CASE# " << test << ":" << endl;
        for(int i = 0; i < Q; i++){
        	bool find = false;
        	for(int j = 0; j < N; j++){
        		if(queries[i] == marbles[j]){
        			cout << queries[i] << " found at " << ++j << endl;
        			find = true;
        			break;
        		}
        	}
        	if(!find)
        		cout << queries[i] << " not found" << endl;
        }
        test++;
    }
    return 0;
}