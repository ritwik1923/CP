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
bool isdate(string d) {
    //cout<<d<<" ";
    bool r=false;
    for(int i=0;i<d.size();i++) {
        if(d[i]>='0'&&d[i]<='9'||d[i]=='-'||d[i]=='.')
       {// cout<<d;
           r=true;}
        else {
            r=false;
return r;
       }
    }
    return r;
}
int dist_pair(int a[], int b[],int n, int m) 
{ 
    set<int> s;
rep(i,0,n) {
 rep(j,0,m)    {
        
     s.insert(a[i]+b[j]);
 }
} 
return s.size();   
} 
  
// Driver function 
int main() 
{ 
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
   cout<<dist_pair(a,b,n,m); 
    return 0; 
}