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
int dp[1001][1001];
int dp_palin[1001][1001];

bool pallindrom(string str , int i , int j) {
    while(i<=j) {
        if(str[i] != str[j]) return 0;
        i++ , j--;
    }
    return 1;
}

int MCM(string str , int i , int j) {
    if(i > j) return 0;
    //if(i == j) return 1;

    if(dp[i][j] != -1)
        return dp[i][j];
    //pallindrom fn
    if(dp_palin[i][j] != -1)
        return dp_palin[i][j];
    if(pallindrom(str , i , j)) {
    cout<<"@ i: "<<i<<" j: "<<j<<"\n";
        return dp_palin[i][j] = 1;
    }
    int res = 10000;
    for(int k = i ; k < j ; k++) {
        int ans = 0 , left , right;
        if(dp[i][k] == -1)
            left = MCM(str , i , k);
        else
            left = dp[i][k];
        if(dp[k+1][j] == -1)
            right = MCM(str , k + 1 , j);
        else
            right = dp[k+1][j];
        ans = right + left;
        cout<<"l: "<<left<<" r: "<<right<<" ans: "<<ans<<" - ";
        res = min(res,ans);

    }
    cout<<res<<" i: "<<i<<" j: "<<j<<"\n";
    return dp[i][j] = res;
}

/*You are required to complete below method */
int mcm_pallindrom(string str)
{
    for(int i = 0;i <= str.size() ;i++) {
        for(int j =  0; j <= str.size() ;j++) {
            dp[i][j] = -1;
            dp_palin[i][j] = -1;
        }
    }
    return MCM(str , 0 , str.size() - 1);
   //Your code here
}
 int main() {
    string y = "bbbabbabab";
    //string y = "aaabba";
    cout<<mcm_pallindrom(y);
    //cout<<knapsack(wt,val,w,n);
    return 0;
}


