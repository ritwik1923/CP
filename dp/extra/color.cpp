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
#define Max 1000

int dp[Max + 1][Max + 1];
int _knapsack(int n,int k) {
    if(n == 0 || k == 0) {
        return 0;
    }
    if(dp[n][k] != -1) return dp[n][k];
    if(n - 2 >= 0)
        dp[n][k] = (1+_knapsack(n-2,k-1)+dp[n][k]);
    if(n - 1 >= 0)
        dp[n][k] = (1+_knapsack(n-1,k-1)+dp[n][k]);
    //if(n  >= 0)
      //  dp[n][k] = max(_knapsack(n,k-1),dp[n][k]);
}
void knapsack(int n,int w) {
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= w ;j++) {
            dp[i][j] = -1;
        }
    }
    cout<<_knapsack(n,w);
}
int main() {
    int n,w;
    n = 3;
    w = 99;
    int wt[] = {9,2,4};
    int val[] = {1,1,1};
    knapsack(n,w);
    //cout<<knapsack(wt,val,w,n);
    return 0;
}


