#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define fox(i, k, n, x) for (ll i = k; k < n ? i < n : i > n; k < n ? i += x : i -= x)
#define ll long long
#define deb(x) cout << #x << "=" << x << " "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"



ll ncr[1001][1001];
ll mod = 1000000007;


ll _nCr(ll n, ll r)
{
    if (ncr[n][r] == -1)
        ncr[n][r] = (_nCr(n - 1, r) + _nCr(n - 1, r - 1));
    return ncr[n][r] % mod;
}
ll factorial(ll n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
ll nCr(ll n, ll r)
{
    // code here
    if (r > n)
        return 0;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= r; j++)
        {
            ncr[i][j] = -1;
        }
    }
    for (ll i = 0; i <= n; i++)
    {
        ncr[i][0] = 1;
        ncr[i][i] = 1;
    }
    return _nCr(n, r);
}
void solve()
{
    cout<<nCr(4,2);
}


int main()
{
    ll t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}





