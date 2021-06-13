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
#define mod LONG_MAX

int powersum(ll n) {
    if(n<9) return 1;
    if(n%9 == 0 ) return (n/9);
    return ((n/9) + 1);
}

int main() {
    ll t;
     cin>>t;
     while(t--) {
         
         string s,sub_s;
         cin>>s>>sub_s;
         map<char, ll > ms,msub_s;
         rep(i,0,s.size()) {
             ms[s[i]]++;
         }
         rep(i,0,sub_s.size()) {
             msub_s[sub_s[i]]++;
             ms[sub_s[i]]--;
         }
          
         vector <char> result;
         map<char, ll >:: iterator j = msub_s.begin();
         for(auto i : ms ) {
             if(i.F <= j->F) {
                 ll n = i.S; 
                 char a = i.F;
                 rep(i,0,n) {
                   result.pb(a);
               } 
               
               ms.erase(a);
             }
             else break;
         }
         rep(i,0,sub_s.size()) {
         
            result.pb(sub_s[i]);
             
         }
         for(auto i : ms) {
            ll n = i.S; 
            char a = i.F;
            rep(i,0,n) {
               result.pb(a);
            }  
         }
         for (auto x : result) {
             cout<<x;
         }
        cout<<"\n";

         
         
     }
    return 0;
}





















