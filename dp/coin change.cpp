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
//#define near_one (a[i+1][j]==0&&a[i][j+1]==0&&(a[i-1][j]==0&&i-1>=0)&&(a[i][j-1]==0&&j-1>=0))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

long long int Max = 1000;

    long long int dp[1000 + 1][1000 + 1];
    long long int _knapsack(int wt[],int w,int n) {

        if(dp[n][w] != -1) return dp[n][w];
        if(wt[n-1] <= w) {

                ///for 1/0 knapsack
            //return dp[n][w] =  _knapsack(wt,val,w - wt[n-1],n - 1)+_knapsack(wt,val,w,n - 1);
                ///for unbounded knapsack
            return dp[n][w] = _knapsack(wt,w - wt[n-1], n )+_knapsack(wt,w,n - 1);

        }
        if(wt[n-1] > w) return dp[n][w] = _knapsack(wt,w,n - 1);
    }
    long long int knapsack(int wt[],int w,int n) {
        for(int i = 0;i < n+1;i++) {
            for(int j =  0; j <= w ;j++) {
                dp[i][j] = -1;
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }
        long long int res = _knapsack(wt,w,n);
        cout<<_knapsack(wt,w,n)<<"\n---------\n";
        for(int i = 0;i < n+1;i++) {
            for(int j =  0; j <= w ;j++) {
                if(dp[i][j]!=-1)
                cout<<dp[i][j]<<" ";
            else
                cout<<"_ ";
            }
            cout<<"\n";
        }
        return res;
    }


int main()
 {
	//code
	int t = 1;
	//cin>>t;
	while(t--) {
	    int n = 4;
	    //cin>>n;
	    int wt[3] = {2,1,1};
	    cout<<knapsack(wt,n,3)<<"\n";
	}
	return 0;
}
