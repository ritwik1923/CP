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
const ll me = 100025;
const ll mod = 0x3b9aca07;

bool isPossible(ll arr[], ll n, ll m, ll curr_min) ;
ll min_pages(ll arr[], ll n, ll m) ;
int main(){
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t --){
        ll n,c;
        cin >> n; ll a[n];
        for(ll i = 0; i < n; i ++)
            cin >> a[i];
        cin>>c;


   cout<<"\nMinimum number of pages = "<<min_pages(a, n, c)<<endl;
    }
   return 0;
}
bool isPossible(ll arr[], ll n, ll m, ll curr_min){
   ll studentsRequired = 1;
   ll curr_sum = 0;cout<<curr_min<<" ";
   for (ll i = 0; i < n; i++){
      if (arr[i] > curr_min)
         return false;
      if (curr_sum + arr[i] > curr_min){
         studentsRequired++;
         curr_sum = arr[i];
         if (studentsRequired > m)
            return false;
      }
      else
         curr_sum += arr[i];
   }
   return true;
}
ll min_pages(ll arr[], ll n, ll m){
   long long sum = 0;
   if (n < m)
      return -1;
   for (ll i = 0; i < n; i++)
      sum += arr[i];
   ll minimum = 0, maximum = sum;
   ll result = INT_MAX;
   while (minimum <= maximum){
      ll mid = (minimum + maximum) / 2;
      if (isPossible(arr, n, m, mid)){
         result = min(result, mid);
         maximum = mid - 1;
      }
      else
         minimum = mid + 1;
   }
   return result;
}