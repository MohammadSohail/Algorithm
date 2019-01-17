#include<bits/stdc++.h>
#define pdd pair<double, double>

using namespace std;

typedef long long ll;

//double x,y;

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}


double bin_search(double x,double y,double c){

    double lo = 0, high = min(x,y),mid,step = 0;

    while(lo - high < 1e-8 && step++ < 1000){

        mid = (lo+high)/2;
        double p = sqrt(y*y - mid*mid);
        double q = sqrt(x*x - mid*mid);
        pdd A = make_pair(0, 0);
        pdd B = make_pair(mid, p);
        pdd C = make_pair(mid, 0);
        pdd D = make_pair(0, q);


        pdd c1 = lineLineIntersection( A, B, C, D);
        pdd z1 = make_pair(c1.first, 0.0);
//        cout << c1  << " c1 " << z1 << " z1 "<< endl;

        double ans = sqrt( pow( c1.first - z1.first, 2) + pow( c1.second - z1.second, 2));

        //if(abs(ans-mid) <= 1e-8 )return mid;
         if(ans < c)high = mid;
        else lo = mid ;

    }

    return lo;
}

int main(){

    int t;
    scanf("%d",&t);

    for(int kase = 1; kase <= t; kase++){

        double x,y,c;
        scanf("%lf %lf %lf",&x,&y,&c);

        printf("Case %d: ",kase);

        double zRange = x+y;

        double res = bin_search(x,y,c);
        cout << setprecision(10) << res << endl;
    }

    return 0;
}
