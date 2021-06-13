#include<bits/stdc++.h>
#include<iostream>
#include<vector>
 #include <algorithm>
// #include <boost/multiprecision/cpp_int.hpp>
//https://www.boost.org/doc/libs/1_66_0/libs/multiprecision/doc/html/index.html
// using boost::multiprecision::cpp_int;
using namespace std;
#define gc getchar_unlocked
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define sline(x)	getline(cin,x);
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << " "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Endl cout<<"\n"
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
//#define near_one (a[i+1][j]==0&&a[i][j+1]==0&&(a[i-1][j]==0&&i-1>=0)&&(a[i][j-1]==0&&j-1>=0))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

vector<ll> prime_nos;

void sieve(ll n)
{
    //0 -> prime no
    //1 -> not prime no

    ll a[n + 1] = {0};

    for (ll i = 2; i * i <= n; i++)
    {

        for (ll j = i * i; j <= n; j += i)
        {
            a[j] = 1;
        }
    }
    rep(i, 2, n + 1) if (!a[i])
        prime_nos.push_back(i);
}

void segmented_sieve(ll l, ll r, bool inrange)
{
    if (l == 1)
        l++;
    ll maxn = r - l + 1;
    ll a[maxn] = {0};
    //0 -> prime no
    //1 -> not prime no
    for (ll p : prime_nos)
    {
        // cout<<p<<" ";
        if (p * p <= r)
        {
            ll i = (l / p) * p; // generate composite no
            if (i < l)          // which is multiple of p in
                i += p;         // from begin of range

            for (; i <= r; i += p)
            {
                if (i != p)       // dont mark itself -> prime no.
                    a[i - l] = 1; // Composite No.
            }
        }
        else {
            // cout<<p<<" ";
            break;
        }
    }

    
    rep(i, 0, maxn) if (!a[i])
        prime_nos.push_back(i + l);
    
}

void segmentedSieve(ll l, ll r, bool inrange)
{
    sieve(1e5);
    if(r - l + 1 > 1e5)
    {

        ll i = 1;
        bool g = 1;
        while (g)
        {
            ll st = l + (i * 1e5);
            ll end;
            if (l + ((i + 1) * 1e5) > r)
            {
                end = r;
                g = 0;
            }
            else
            {
                end = l + ((i + 1) * 1e5)-1;
            }
            i++;
            // deb2(st,end);
            segmented_sieve(st, end, 1);
        }
    }
    else
    {
        segmented_sieve(l, r, 1);
    }
}

void factor(ll n,map<ll,ll> &fac) {
    ll i = 0;
    // map<ll,ll> fac;
    while(n > 1){
        ll f = prime_nos[i];
        if(n%f == 0) n/=f , fac[f]++;
        else ++i;
    }

}

int main() {
    ll n ;
    // cin>>n;
    segmentedSieve(1,1e10,1);
    // map<ll,ll> fac;
    // factor(n,fac);
    // for(auto i : fac)
    // {
    //     cout<<i.F<<" "<<i.S<<"\n";
    // }
    return 0;
}

