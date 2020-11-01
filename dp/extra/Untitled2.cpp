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

void knapsack(int wt[],int val[],int w,int n) {
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= w ;j++) {
            dp[i][j] = 0;
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;

        }
    }
    for(int i = 1;i < n+1;i++) {
        for(int j =  1; j <= w ;j++) {

            if(wt[i - 1] <= j) {
                    ///1/0
               // if(dp[i-1][j - wt[i - 1]] || dp[i-1][j]) dp[i][j] = 1;
                    ///unbounded
                if(dp[i][j - wt[i - 1]] || dp[i-1][j]) dp[i][j] = 1;
            }
            else if(wt[i - 1] > j) dp[i][j] = dp[i-1][j];

        }
    }
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= w ;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main() {
    int n,w;
    n = 3;
    w = 10;
    int wt[] = {1,2,7};
    int val[] = {1,1,1,1};
    knapsack(wt,val,w,n);
    //cout<<knapsack(wt,val,w,n);
    return 0;
}

