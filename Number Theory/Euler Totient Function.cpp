# include <bits/stdc++.h>
using namespace std;
#define N 1000020
vector <int> IsPrime(N);
vector <int> prime;
void sieve()
{
    IsPrime[0] = IsPrime[1] = 1;
    IsPrime[2] = 0;
    for(int i = 4;i < N; i += 2)
        IsPrime[i] = 1;

    int SQT = sqrt( N );
        for(int i = 3; i <= SQT; i += 2) {
        if(IsPrime[i] == 0) {
            for(int j = i*i; j <= N;j += 2*i)
                IsPrime[j] = 1;
        }
    }
    // sieve ends here

    prime.push_back(2);
    for(int i = 3;i < N;i += 2) {
        if(IsPrime[i]==0)
            prime.push_back(i);
    }

}

int eulerPhi ( int n ) {
    int res = n;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
            }
            sqrtn = sqrt ( n );
            res /= prime[i];
            res *= prime[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}

int a[N];

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);
    sieve();
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        if(IsPrime[x] == 0)cout << x-1 << endl;
        else cout << eulerPhi(x) << endl;
    }

    return 0;
}


//    for(int i = 1; i < N; i++){
//        a[i] = eulerPhi(i);
//       // cout << i << " " << a[i] << endl;
//    }

