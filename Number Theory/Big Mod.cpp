#define ll long long
ll BigMod(ll base,ll power,ll mod)
{
    if(power == 0) return 1;
    if(power%2)
    {
        ll temp = (BigMod(base,power-1,mod));
        return ((base%mod)*(temp%mod))%mod;
    }
    else
    {
        ll temp = BigMod(base,power/2,mod);
        return ((temp%mod)*(temp%mod))%mod;
    }
}

///M O D    H A N D L E R////////////////////
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


///I T E R A T I V E ///////////////////////////////


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
