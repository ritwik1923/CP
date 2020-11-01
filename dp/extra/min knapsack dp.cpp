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
int dp[1000 + 1][1000 + 1];
    int _knapsack(int wt[],int val[],int w,int n) {
        if(dp[n][w] != -1) return dp[n][w];
        if(wt[n-1] <= w) {
                int taken = 0;
                int not_taken ;
                ///for 1/0 knapsack
                if(val[n-1] != -1)
                taken = val[n-1] + _knapsack(wt,val,w - wt[n-1],n);
                not_taken = _knapsack(wt,val,w,n - 1);
                int ans = 1000000;
                if(taken < ans) ans = taken;
                if(not_taken < ans && not_taken != 0) ans = not_taken;
                // deb(ans) , deb2(taken,not_taken);
            return dp[n][w] = ans;
                ///for unbounded knapsack
            //return dp[n][w] = max(1 + _knapsack(wt,val,w - wt[n-1], n ),_knapsack(wt,val,w,n - 1));

        }
        if(wt[n-1] > w) return dp[n][w] = _knapsack(wt,val,w,n - 1);
    }
    int knapsack(int wt[],int val[],int w,int n) {
        for(int i = 0;i < n+1;i++) {
            for(int j =  0; j <= w ;j++) {
                dp[i][j] = -1;
                if(j == 0) dp[i][j] = 0;//1
                if(i == 0) dp[i][j] = 1000000;
            }
        }

    cout<<_knapsack(wt,val,w,n)<<"\n";
        for(int i = 0;i < n+1;i++) {
            for(int j =  0; j <= w ;j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
}
int main() {
    int n,w;
    n = 5;
    w = 17;
    int val[] = {-1, -1, 4, 3, -1};//{20, 10, 4, 50, 100};
    //int val[] = {20, 10, 4, 50, 100};
    int wt[] = {1,2,3,4,5};
    knapsack(wt,val,w,n);
    //cout<<knapsack(wt,val,w,n);
    return 0;
}

