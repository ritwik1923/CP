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
ll n;
int binary_search_recursion(ll l,ll u,ll arr[])
{
        /*
        1: If array[0] less than or equal to array[length of array - 1], it means the array is not rotated, so return 0.
        2: Initialize start = 0, end = length of array – 1.
        3: Repeat following steps till start less than or equal to end 
           (a) Set mid = (start+end)/2.
           (b) If mid+1 is pivot, then break.
           (c) If array[start] less than or equal to array[mid], it means from start to mid, all elements are in sorted order. Set start = mid+1, so that we look for pivot in second half of the array.
           (d) Else set end = mid-1, to look for pivot in first half.
        */
   if(l<=u)   {
       ll m=l+(u-l)/2;
           cout<<(m)<<" ";
           // i have check on element greater 
           // than present on before it not after as it is sorted
        if(( m >= 0 && arr[ m ] <= arr[ m - 1 ] ))
        return m;
        else if( arr[ m ]  <= arr[ u ] ) {
                // is sorted than check min or pivot in next half
                return  binary_search_recursion(l,m,arr);
        }
        else if( arr[ l ] <= arr[ m ] ) {
                // is sorted than check min or pivot in next half
                return  binary_search_recursion(m,u,arr);
        }
   }
      
        return -1;

}
int main() 
{ 

    //    ll n;
        cin>>n;
        ll a[n];
        rep(i,0,n) cin>>a[i];
        cout<<binary_search_recursion(0,n,a);
        return 0;
} 
