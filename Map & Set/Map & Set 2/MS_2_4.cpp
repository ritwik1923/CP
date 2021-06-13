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
  
void replaceElements(int arr[], int n) 
{ 
    unordered_set<int> s; 
  
    for (int i = 0; i < n; i++) { 
  
        // check whether the element is 
        // repeated or not 
        if (s.find(arr[i]) == s.end()) 
            s.insert(arr[i]); 
  
        else { 
  
            // find the next greatest element 
            for (int j = arr[i] + 1; j < INT_MAX; j++) { 
                if (s.find(j) == s.end()) { 
                    arr[i] = j; 
                    s.insert(j); 
                    break; 
                } 
            } 
        } 
    } 
} 
  
int main() 
{ 
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll s[n],c=0;
        set <ll> a;
       rep(i,0,n) {
           cin>>s[i];
           a.insert(s[i]);
           }
           //set <int, greater <int> > :: iterator itr;
       rep(i,0,n) {
           rep(j,i+1,n) {
               // find any element is there a[j]-a[i] and sum of diff and a[j]
               auto itr=a.find(s[j]-s[i]+s[j]);
               if((itr)!=a.end()) {
                   cout<<s[i]<<" "<<s[j]<<" "<<(*itr)<<"\n";
               }

           }
       } 
    }
} 