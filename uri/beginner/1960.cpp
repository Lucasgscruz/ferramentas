#include <iostream>
#include <string>

using namespace std;

// Converte numero hindu-arabico para romano
string dec2rom(int dec) {
	int denary = dec;
	string roman = "";
	
    int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romano[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    while(true){
        if (denary == 0)
        	break;
        int i = 0;
        while(denary > 0){
            if(denary >= decimal[i]){
            	roman += romano[i];
            	denary -= decimal[i];
            } 
            else
            	i++;
        }
    }
    
    return roman;
}

int main(){
	int N;
	cin >> N;
	cout << dec2rom(N) << endl;
	return 0;
}