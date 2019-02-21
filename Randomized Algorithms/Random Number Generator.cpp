# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(a, b)        ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define ran(a, b)           rng() % ((b) - (a) + 1) + (a)


bool check (int n)
{
    if (n == 0 || n == 1){
        return false;
    }
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    srand(time(0));
    int n;
    cin >> n;

    if(check(n)){
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }

    for(int i = 1; i <= 300; i++){

        int x = random(2, n);
        if(check(x)){
            int y = n - x;
            if(y > 0 && check(y)){
                cout << 2 << endl;
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }

    for(int i = 1; i <= 300; i++){
        int x = random(2, n);
        if(check(x)){
        for(int j = 1; j <= 300; j++){
            int y =  random(2, n);
            if(check(y)){
                if(x+y < n){
                    int z =abs(n - (x + y));
                    if(check(z)){
                        cout << 3 << endl;
                        cout << x << " " << y << " " << z << endl;
                        return 0;
                    }
                }
            }
        }
        }
    }

    return 0;
}

