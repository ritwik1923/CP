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
typedef set<ll>		sll;
 
/* Returns true if the there is a subarray of arr[] with a sum equal to 'sum' 
   otherwise returns false.  Also, prints the result */
int subArraySum(sll s, ll n) 
{ 
    ll c=0,count=0;
    //sort(arr,arr+n);
    ll arr[s.size()],i=0;
    set <ll, greater <ll> > :: iterator itr;
for (itr = s.begin(); itr != s.end(); ++itr) 

    { arr[i++]=*itr; 

    }      //  cout<<"\n";
    rep(i,0,n-1) {
        if((arr[i+1]-arr[i])==1) {c++;
        //cout<<arr[i]<<","<<arr[i+1]<<"\n";
        }
        else
        {
            c=0;
        }
        count=max(count,c);

    }
        cout<<count+1<<"\n";
        return 0;
} 
  
// Driver program to test above function 
int main() 
{ 
    ll t;
    cin>>t;

    while(t--){
        ll n;
    cin>>n;
    set<ll> a;

    rep(i,0,n) {
        ll x;
        cin>>x;
        a.insert(x);
        }
          cout<<*(a.begin())<<"\n";
    //subArraySum(a, n); 
    }return 0; 
} 