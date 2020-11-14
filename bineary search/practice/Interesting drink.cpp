#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// //https://www.boost.org/doc/libs/1_66_0/libs/multiprecision/doc/html/index.html
// using boost::multiprecision::cpp_int;
using namespace std;
#define gc getchar_unlocked
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define sline(x)	getline(cin,x);
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define star	printf("*\n")
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
//#define near_one (a[i+1][j]==0&&a[i][j+1]==0&&(a[i-1][j]==0&&i-1>=0)&&(a[i][j-1]==0&&j-1>=0))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

// 5
// 3 10 8 6 11
// 4
// 1
// 10
// 3
// 11

int lowerlimit(ll a[],ll n,ll q) {
    int low = 0, high = n-1;
    int ans = 0;
    while(low <= high) {
        int mid = low + (high-low)/2;

        //deb(a[mid]) , deb(mid),deb2(low,high);

        if(a[mid] <=  q)  {
            //star;
            ans = mid + 1 , low = mid + 1;
        }
        else
            high = mid - 1;

    }

    return ans;
}


int main() {
    ll n,t;
   cin>>n;
// n = 5;
    ll a[n];
    // = {3 ,10 ,8 ,6 ,11};
    //t=1;
    rep(i,0,n) cin>>a[i];
    sort(a,a+n);
    int q,x;
    cin>>q;
    while(q--){
    cin>>x;
    cout<<lowerlimit(a,n,x)<<"\n";
    }

}
