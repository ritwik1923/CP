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

int dp[Max+1][Max+1];

int CPS(string s,int i,int j) {
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j]) {
        //extreme end r same
        return dp[i][j] = 1 + CPS(s,i, j - 1) + CPS(s,i + 1,j);
    }
    if(s[i] != s[j]) {
        //extreme end r not same
        return dp[i][j] = CPS(s,i, j - 1) + CPS(s,i + 1,j) - CPS(s,i + 1, j - 1);
    }
}


int main() {
    int n,w;
    n = 3;
    w = 10;
    string x = "BBABCBCAB";

    rep(i,0,x.size()) {
        rep(j,0,x.size()) {
            dp[i][j] = -1;
        }
    }

    cout<<CPS(x,0,x.size()-1)<<"\n";

    for(int i = 0;i < x.size()+1;i++) {
        for(int j =  0; j <= x.size() ;j++) {
            if(dp[i][j]!=-1)
                cout<<dp[i][j]<<" ";
            else
                cout<<"_ ";
        }
        cout<<"\n";
    }
    return 0;
}


