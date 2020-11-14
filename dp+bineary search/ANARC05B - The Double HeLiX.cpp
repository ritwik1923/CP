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

int dp[1001][1001];

int seq(int a[],int b[],int n,int m) {

    if(n <= 0 && m > 1) return b[m-1]+seq(a,b,0,m-1);
    if(m <= 0 && n > 1) return a[n-1]+seq(a,b,n-1,0);

    if(n <= 0 && m <= 0) return 0;
    //if(dp[n][m] != -1) return dp[n][m];
    if(a[n - 1] == b[m - 1] ) {
        int seql = seq(a,b,n-1,m-1);
        //int seqr = seq(b,a,m-1,n-1);
        //deb2(seql,seqr);
         //dp[n][m] =
        return a[n - 1] + seql;
    }
    else
    {
        int seql = a[n-1]+seq(a,b,n-1,m);
        int seqr = b[m-1]+seq(a,b,n,m-1);
        //cout<<"* ";
        //deb2(seql,seqr);
        //dp[n][m] =
        return max(seql,seqr);
    }

}

int main() {
    rep(i,0,13) {
        rep(j,0,11) {
            dp[i][j] = -1;
        }
    }
    int a[] = {3 ,5 ,7 ,9 ,20 ,25 ,30 ,40 ,55 ,56 ,57 ,60 ,62};
    int b[] = {1 ,4 ,7 ,11 ,14 ,25 ,44 ,47 ,55 ,57 ,100};
    cout<<seq(a,b,13,11);
}
