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

int main() {
    ll n,t;
    cin>>n>>t;
     double a[n];
     //= {15 ,5 ,3 ,7 ,9 ,14 ,0};
    //t=1;
     rep(i,0,n) cin>>a[i];
    sort(a,a+n);
    double ans = 0;
    int j = 0;
    rep(i,1,n) {
       // cout<<(a[i] - a[j])/2<<" ";
       ans = max(ans,(a[i] - a[j])/2);
        j = i;
    }

    //cout<<fixed<<setprecision(10)<<ans<<"\n";
    if(a[0] != 0) {
        ans = max(ans,a[0]-0);

    }
    //cout<<fixed<<setprecision(10)<<ans<<"\n";
    if(a[n-1] != t) {
        ans = max(ans,t - a[n-1]);

    }
    cout<<fixed<<setprecision(10)<<ans;
    //cout<<ans;
}

