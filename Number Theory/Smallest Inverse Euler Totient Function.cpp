# include <bits/stdc++.h>
using namespace std;
#define N 200000001
int prec[N];
int phi[N];

void phisieve(){
    for(int i = 1; i <= N; i++){
        phi[i] = i;
    }
    memset(prec,0,sizeof prec);
    prec[1] = 1;
    for(int i = 2; i <= N; i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(int j = 2*i; j <= N; j+=i){
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
        if(prec[phi[i]] == 0)prec[phi[i]] = i;
    }
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);
    phisieve();
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        if(prec[x] == 0)printf("-1\n");
        else printf("%d\n",prec[x]);
    }

    return 0;
}
