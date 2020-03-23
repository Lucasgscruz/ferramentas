/*
Equacao da reta
https://www.todamateria.com.br/equacao-da-reta/

Bissetriz perpendicular de uma reta
https://www.youtube.com/watch?v=qc9gcY-24bk

*/

// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct point{
    double x, y;
};

int main(){
    int T, caso = 1;
    point a1, a2, b1, b2, average_A, average_B;
    double mA, mB; // Coeficiente angular
    double C1, C2, X, Y;

    cin >> T;
    while(T--){        
        cin >> a1.x >> a1.y;
        cin >> b1.x >> b1.y;
        cin >> a2.x >> a2.y;
        cin >> b2.x >> b2.y;

        average_A = {(a1.x + a2.x)/2, (a1.y + a2.y)/2};
        average_B = {(b1.x + b2.x)/2, (b1.y + b2.y)/2};

        // printf("%f\n",average_A.x);
        // printf("%f\n",average_A.y);
        // printf("%f\n",average_B.x);
        // printf("%f\n",average_B.y);


        mA = (a2.y - a1.y) / (a2.x - a1.x); // m = (y2 - y1) / (x2 - x1)
        mB = (b2.y - b1.y) / (b2.x - b1.x);
        mA = -1 / mA;
        mB = -1 / mB;

        printf("%f\n",mA);
        printf("%f\n",mB);

        C1 = -mA * average_A.x + average_A.y; // y = mx + C (equacao da reta) -> C = -mx + y
        C2 = -mB * average_B.x + average_B.y;

        // Set straight equation system. Find intersection point
        X = (C1 + C2) / (mA + mB);
        Y = mA * X + C1;

        cout << "Caso #" << caso-- << ": " << X << " " << Y << endl;
    }
    return 0;
}