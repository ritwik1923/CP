#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

/*
template<typename... T> 
void read(T&... args) {
  ((cin>>args),...);
}
template<typename... T> 
void write(T&... args) {
  ((cout<<args<<" "),...);
}

*/

int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

/*
int main() {
    ios_base::sync_with_stdio(0);
    int t, i, j, k, p, q, r, x, y, u, v, n, m;

    return 0;
}

*/
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll m,n;
        cin>>n>>m;
        set<ll> a;
        set <ll> b;

      //  ll a[n+m];//,b[m];
        rep(i,0,n) {
            ll x;
            cin>>x;
            a.insert(x);
        }
        rep(i,0,m) {
            ll x;
            cin>>x;
            b.insert(x);
        }

        ll r=0;
       // set <ll, greater <ll> > :: iterator itr;
        for (auto itr = b.begin(); itr!= b.end(); ++itr) { 
                if(a.find(*itr)!=a.end())
                r=1;
                else
                {
                    r=0;
                    break;
                }
                //cout<<*itr<<" ";
    }
    if(r) cout<<"Yes";
    else 
    cout<<"No";
        cout<<"\n";
        
    }
  return 0;
}