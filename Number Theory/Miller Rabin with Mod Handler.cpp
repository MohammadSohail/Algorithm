#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL mulmod(LL a, LL b, LL mod)
{
    LL x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

LL BigMod(LL base,LL power,LL mod)
{
    if(power == 0) return 1;
    if(power%2)
    {
        LL temp = (mulmod(base,power-1,mod));
        return ((base%mod)*(temp%mod))%mod;
    }
    else
    {
       LL temp = mulmod(base,power/2,mod);
        return ((temp%mod)*(temp%mod))%mod;
    }
}


bool miillerTest(LL d, LL n)
{
    LL a = 2 + rand() % (n - 4);

    LL x = BigMod(a, d, n);

    if (x == 1  || x == n-1)
       return true;

    while (d != n-1)
    {
        x = mulmod(x,x,n);
        d *= 2;

        if (x == 1)      return false;
        if (x == n-1)    return true;
    }

    return false;
}


bool isPrime(LL n, LL k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    LL d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (LL i = 0; i < k; i++)
         if (!miillerTest(d, n))
              return false;

    return true;
}


int main()
{
    LL k = 100;
    LL t;
    cin >> t;
    while(t--){

    LL n;
    cin >> n;

       if(isPrime(n, k))cout << "YES" << endl;
       else cout << "NO" << endl;
    }
    return 0;
}
