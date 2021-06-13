/* An efficient program to print subarray with sum as given sum */
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
 
// Driver program to test above function 
int main() 
{ 
    ll t;
    cin>>t;

    while(t--){
        ll n,k;
    cin>>k>>n;
        set<ll> s;
    rep(i,0,n) {
        ll x;
        cin>>x;
    if(x>k)
    s.insert(x-k);
    else
    {
    s.insert(x+k);
    }
    }

set <int, greater <int> > :: iterator itr;
/*
itr=s.;
itr--;
*/
    //rep(i,0,n) cout<<a[i]<<"-";
    for  (auto itr=s.begin(); itr != s.end(); itr++) 
     /// *itr; 
        cout<<*(s.begin())<<"   "<<*itr<<"\n"; 

    cout<<*(s.begin())-*(s.end())<<"\n"; 
    }return 0; 
} 