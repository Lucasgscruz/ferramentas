#include <iostream>
 
using namespace std;
 
int main() {
    int i = 0, n = 0;
    float total = 0;
    cin >> n;
    
    while(n >= 0){
        total += n;
        i++;
	   cin >> n;
    }
    
    cout << fixed;
    cout.precision(2);
    cout << total/i << endl;
    return 0;
}