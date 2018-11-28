#include<bits/stdc++.h>
using namespace std;

int n;
int a[100][100];
int sum[100][100];

/// cummulative sum
void csum()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
}

///sum of ranged rectangle numbers

int findsumofRect(int a,int b,int c,int d)
{
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1];
    }
    return ans;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
            sum[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    csum();

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << findsumofRect(a,b,c,d) << endl;
}

/*
3
1 1 1
1 1 1
1 1 1

2 2 3 3

answer:

1 2 3
2 4 6
3 6 9

4

*/





