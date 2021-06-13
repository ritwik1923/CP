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
 
/* Returns true if the there is a subarray of arr[] with a sum equal to 'sum' 
   otherwise returns false.  Also, prints the result */
int subArraySum(ll arr[], ll n) 
{ 

    ll best = arr[0],i,ma=arr[0]; 

    for (i = 1; i < n; i++) 
    { 
      //to find max   
     ma=max(ma+arr[i],arr[i]);
     //to find ma is actually the max no. the array
     best=max(ma,best);
     cout<<best<<" ";

    } 
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
    ll a[n];
    rep(i,0,n) cin>>a[i];
    subArraySum(a, n); 
    }return 0; 
} 