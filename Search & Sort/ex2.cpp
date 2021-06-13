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
const ll me = 100025;
const ll mod = 0x3b9aca07;
int ice_cream(ll a[],ll n){
    ll c=0,c5=0,c10=0,c15=0;
    map<ll,ll> m;

        
    rep(i,0,n) {
               if(a[i]==5){ c+=5;m[5]++;}
               else if(a[i]==10){
                   if(m[5]==0) return 0;
                   else if(m[5]>0){ m[5]--;m[10]++;}
               }
               else if(a[i]==15){ 
                   if(m[5]<=1||m[10]==0) return 0;
                   else if(m[5]>=2) {
                       m[5]-=2;
                   }
                   else if(m[10]>0){ m[10]--;}
                     m[15]++;
               } for(auto i : m) cout<<i.F<<" "<<i.S<<" \n";
               cout<<"\n---------------------\n";
          }                  
        
       return 1;
}
int main() {
    ll t;
    cin>>t;
    while(t--) {
       ll n;
       cin>>n;
       ll a[n];
       rep(i,0,n) cin>>a[i];
       if(ice_cream(a,n)) cout<<"YES";
       else cout<<"NO";
        
        cout<<"\n";
    }
}