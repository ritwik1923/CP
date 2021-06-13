#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << " "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
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

void NGL(ll a[],ll n) {
vector <ll> v;
stack <ll> s;
Fo(i,n-1,-1) {
    if(s.size()==0) v.push_back(-1);
    else if(s.size()>0&&a[i]<s.top()) v.push_back(s.top()); 
    else if(s.size()>0&&a[i]>=s.top()) {
        while(s.size()>0&&a[i]>=s.top()) s.pop();
        if(s.size()==0) v.push_back(-1);
        else if(a[i]<s.top()) v.push_back(s.top()); 
    }
    s.push(a[i]);
}
reverse(v.begin(),v.end());
for(int i=0;i<n;i++) cout<<v[i]<<" "; 
}

int main() {
    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n) cin>>a[i];
    NGL(a,n);
}