int ext_gcd ( int A, int B, int *X, int *Y ){
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
///IF M is Prime

int x = bigmod( a, m - 2, m ); // (ax)%m = 1


/// IF M is not Prime
int mod_inv(int a,int m){
    int x,y;
    int g = ext_gcd(a,m,&x,&y);
    if(g != 1)return 0;
    else{
        x = (x % m + m) % m;
        return x;
    }
}

///Finding the modular inverse for every number modulo  m

void modInv(){

    inv[1] = 1;
    for(int i = 2; i < m; ++i){
        inv[i] = (m - (m/i) * inv[m%i] % m) % m;
    }
}
