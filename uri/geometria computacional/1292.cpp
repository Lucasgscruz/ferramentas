#include <iostream>
#include <math.h>

using namespace std;

int main(){
	 double input;
	 while(cin>>input){
	 	cout << fixed;
	 	cout.precision(10);
	 	cout<< input*sin(108*acos(-1)/180)/sin(63*acos(-1)/180)<<endl;
	 }
	return 0;
}