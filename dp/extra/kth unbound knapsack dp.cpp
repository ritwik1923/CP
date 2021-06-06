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
int _knapsack(int w,int n,int k,int K) {
    if(k == 0) {
        return 0;
    }
    if(dp[n][w] != -1) return dp[n][w];
    // if(0 <= w) {

            ///for unbounded knapsack
        return dp[n][w] = (_knapsack(w - 1, n,k-1,K )+_knapsack(w,n - 1,K,K));

    // }
    // if(0 > w) return dp[n][w] = _knapsack(w,n - 1,K,K);
}
///n = is no.
///w is height
void knapsack(int w,int n,int k) {
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= w ;j++) {
            dp[i][j] = -1;
            if(i == 0)
               dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;

        }
    }
    cout<<_knapsack(w,n,k,k);
        for(int i = 0;i < n+1;i++) {
            for(int j =  0; j <= w ;j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
}
int main() {
    int n,w,k;
    n = 3;
    w = 3;
    k = 2;
    // int wt[] = {1,2,3};
    knapsack(w,n,k);
    //cout<<knapsack(wt,val,w,n);
    return 0;
}

