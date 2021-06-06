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
int _knapsack(int wt[],int w,int n) {

    if(dp[n][w] != -1) return dp[n][w];
    if(wt[n-1] <= w) {

            ///for 1/0 knapsack
        return dp[n][w] =  _knapsack(wt, w - wt[n-1],n - 1)+_knapsack(wt, w,n - 1);
            ///for unbounded knapsack
        //return dp[n][w] = _knapsack(wt, w - wt[n-1], n )+_knapsack(wt, w,n - 1);

    }
    if(wt[n-1] > w) return dp[n][w] = _knapsack(wt, w,n - 1);
}
void knapsack(int wt[],int w,int n) {
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= w ;j++) {
            dp[i][j] = -1;
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }
    cout<<_knapsack(wt, w,n)<<"\n---------\n";
    for(int i = 0;i < w+1;i++)
            cout<<i<<" ";
    cout<<"\n";
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= w ;j++) {
            if(dp[i][j]!=-1)
            cout<<dp[i][j]<<" ";
        else
            cout<<"_ ";
        }
        cout<<"\n";
    }
}

int main() {
    int n,w;
    n = 4;
    w = 16;
    int wt[] = {2,5,3,6};
    knapsack(wt, w,n);
    //cout<<knapsack(wt, w,n);
    return 0;
}


