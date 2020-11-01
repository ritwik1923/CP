//https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
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
vector <char> printLCS(string x,string y,int n,int m) {
    vector <char> s;
    while(n > 0 && m > 0) {

        if(x[n-1] == y[m-1]) s.pb(x[n-1])  , n-- ,m--;
        else if(dp[n - 1][m] - dp[n][m - 1] > 0 )  n--;
        else m--;
    }
    reverse(s.begin(),s.end());
    return s;
}
void LCS(string x,string y,int n,int m) {
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= m ;j++) {
            dp[i][j] = 0;
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 0;
        }
    }
    for(int i = 1;i < n+1;i++) {
        for(int j =  1; j <= m ;j++) {

            if(x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else {
                /// longest common subset
                dp[i][j] = 0;
                /// longest common sequence
                //dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= m ;j++) {
            cout<<dp[i][j]<<"";
        }
        cout<<"\n";
    }
    int ans = 0;
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= m ;j++) {
            ans = max(dp[i][j] , ans);
        }
    }

    vector <char> s = printLCS(x,y,n,m);
    for(auto i : s)
        cout<<i;
    cout<<ans;
}
int main() {
    int n,w;
    n = 3;
    w = 10;
    string y = "ba*a?";
    string x = "baaabab";
    LCS(x,y,x.size(),y.size());
    //cout<<knapsack(wt,val,w,n);
    return 0;
}


