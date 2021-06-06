
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

int dp[Max + 1];
int _knapsack(int n) {
    //base condition
    if(n <= 0) {
        return 0;
    }
    if(n <= 2) return dp[n] = n;
    if(dp[n] != -1) return dp[n];
    //condition
    return dp[n] = _knapsack(n-1) + _knapsack(n-2);
}
void knapsack(int n) {
    for(int i = 0;i < n+1;i++) {
        dp[i] = -1;
    }
    cout<<_knapsack(n)<<"\n";
    for(int i = 0;i < n+1;i++) {
        cout<<dp[i] <<"  ";
    }
}
int main() {
    int n = 5;

    knapsack(n);
    //cout<<knapsack(wt,val,w,n);
    return 0;
}

