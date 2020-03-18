#include <bits/stdc++.h>
#define eps 1e-6

using namespace std;

struct point{
    double x, y;
};

int main(){
    int t, caso = 1;
    double a1, b1, c1, a2, b2, c2, D, D1, D2;
    double X, Y;
    point a, b, c, d;
    point ab, cd, o;
    bool x_neg, y_neg;

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
        // printf("%f\n",ab.x);
        // printf("%f\n",ab.y);
        // printf("%f\n",cd.x);
        // printf("%f\n",cd.y);

        a1 = a.x - b.x;
        b1 = a.y - b.y;
        c1 = (a1 * ab.x) + (b1 * ab.y);
        
        a2 = c.x - d.x;
        b2 = c.y - d.y;
        c2 = (a2 * cd.x) + (b2 * cd.y);
        // printf("%f\n",a1);
        // printf("%f\n",c1);
        // printf("%f\n",a2);
        // printf("%f\n",c2);

        D = (a1 * b2 - a2 * b1);
        // printf("%f\n",D);
        if(D < eps and D > -eps){
		  X = 0.00;
		  Y = 0.00;
		}
        else{
        	D1 = (c1 * b2) - (c2 * b1);
            // printf("%f\n",D1);
        	if(D1 < eps and D1 > -eps)
		    	X = 0.00;
			else
		    	X = (D1/D);
            
        	D2 = (a1 * c2 - a2 * c1);
        	
            if(D2 < eps and D2 > -eps)
        	   Y = 0.00;			
            else
				Y = (D2 / D);
        }
        // printf("%f\n",eps);
        printf("Caso #%d: %.2f %.2f\n",caso++, X, Y);
    }
    return 0;
}