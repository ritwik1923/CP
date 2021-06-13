#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define fox(i, k, n, x) for (ll i = k; k < n ? i < n : i > n; k < n ? i += x : i -= x)
#define ll long long
#define deb(x) cout << #x << "=" << x << " "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"


int n,m,o,ans;
int a[1000000];


void solve()
{
    cin>>n;
    rep(i,0,n) cin>>a[i];
    ans = 0;
    ll p = 0;
    rep(i,0,n) {
       
            ans = 2*ans + a[i];
        
        
        deb(ans);
    }
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





