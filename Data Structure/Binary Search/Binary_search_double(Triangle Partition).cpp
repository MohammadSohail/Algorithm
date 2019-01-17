#include<bits/stdc++.h>
using namespace std;

double area(double a, double b, double c){

    double p = (a+b+c)/2.0;
    double ans = sqrt(p*(p - a)*(p - b)*(p - c));
    return ans;
}

double bin_search(double a, double b, double c, double r)
{
    double lo = 0, high = a, mid = 0,step = 0;
    double ans = 0;
    double ABC = area(a,b,c);

      while(lo - high < 1e-8 && step++ < 1000){

        mid = (lo+high)/2;
        double a1 = mid;
        double b1 = (a1 * b)/a;
        double c1 = (a1 * c)/a;
        double ADE = area(a1,b1,c1);
        double BDEC = ABC - ADE;
        double r1 = ADE/BDEC;

        if(r1 > r)high = mid;
        else lo = mid;
    }

    return mid;
}

int main()
{
    int t;
    cin >> t;

    for(int kase = 1; kase <= t; kase++){

        double a,b,c,r;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r);

        double res = bin_search(a,b,c,r);

         printf("Case %d: ",kase);
        printf("%lf\n",res);

    }
}
