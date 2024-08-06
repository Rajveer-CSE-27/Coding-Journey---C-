const int N = 500010;
 
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
    {
    	return 0;
    }
    while (a > 1) 
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
 
        y = x - q * y;
        x = t;
    }
    if (x < 0)
    {
    	x+=m0;
    }
    return x;
}
vector<int> fact(N),inv(N);
 
void build()
{
	fact[0]=1;inv[0]=1;
    fact[1]=1;inv[1]=1;
    for(int i=2;i<N;i++)
    {
    	fact[i]=(fact[i-1]*i)%mod;
    	int curr=modInverse(i,mod);
    	inv[i]=(inv[i-1]*curr)%mod;
    }
}
 
int comb(int n,int r)
{
	//this function will calculate nCr
	if(r>n)
	{
		return 0;
	}
	else 
	{
		int ans=(fact[n]*inv[r])%mod;
		ans*=(inv[n-r]);
		ans%=mod;
		return ans;
	}
}
