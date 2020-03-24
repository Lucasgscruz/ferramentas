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
    int t, caso = 1;
    double a1, b1, c1, a2, b2, c2, D, D1, D2;
    double X, Y;
    point a, b, c, d;
    point ab, cd;

    cin >> t;
    while(t--){
        cin >> a.x >> a.y;
        cin >> c.x >> c.y;
        cin >> b.x >> b.y;
        cin >> d.x >> d.y;

        ab.x = (a.x + b.x) / 2.0;
        ab.y = (a.y + b.y) / 2.0;

        cd.x = (c.x + d.x) /2.0;
        cd.y = (c.y + d.y) / 2.0;

        a1 = a.x - b.x;
        b1 = a.y - b.y;
        c1 = (a1 * ab.x) + (b1 * ab.y);

        // printf("%f,  %f,   %f\n", a1,b1,c1);
        
        a2 = c.x - d.x;
        b2 = c.y - d.y;
        c2 = (a2 * cd.x) + (b2 * cd.y);

        // printf("%f,  %f,   %f\n", a2,b2,c2);

        D = (a1 * b2) - (a2 * b1);
 
    	D1 = (c1 * b2) - (c2 * b1);

    	X = (D1/D);
        
    	D2 = (a1 * c2) - (a2 * c1);
    	
		Y = (D2 / D);

		// mA = (a2.y - a1.y) / (a2.x - a1.x); // m = (y2 - y1) / (x2 - x1)
        // mB = (b2.y - b1.y) / (b2.x - b1.x);
        // mA = -1 / mA;
        // mB = -1 / mB;

        // // printf("%.2f\n", );
        // printf("%f\n",mB);

        // nA = -mA * average_A.x + average_A.y; // y = mx + n (equacao da reta) -> n = -mx + y // coeficiente linear
        // nB = -mB * average_B.x + average_B.y;

        // printf("%f\n",nA);
        // printf("%f\n",nB);

        // // Set straight equation system. Find intersection point
        // X = (-nA + nB) / (mA - mB);
        // Y = mA * X + nA;

        printf("Caso #%d: %.2f %.2f\n",caso++, X, Y);
    }
    return 0;
}