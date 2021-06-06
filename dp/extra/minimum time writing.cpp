
// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
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

int MAX = 101;
int dp[1000 + 1];

    int MTFWC(int l,int N, int I,
                       int D, int C)
    {
    if(l > N) return 100000;
    if(dp[l] != -1) return dp[l];
    int insert, del , copy;
    insert = I + MTFWC(l+1,N,I,D,C);
    del =  D + MTFWC(l-1,N,I,D,C);
    copy =  C + MTFWC(l*2,N,I,D,C);

    return dp[l] = min(insert , min(del , copy));


    }
	int minTimeForWritingChars(int N, int I,
                       int D, int C)
	{
	    // Your code goes here
        for(int i = 0;i < N+1;i++) {
                dp[i] = -1;
        }
        int ans = MTFWC(N,N,I,D,C);
        for(int i = 0;i < N+1;i++) {
                cout<<dp[i]<<" ";
        }

        return ans;
	}

int main() {

    int m[][26] = {{0,6,0},
                   {5,8,7},
                   {0,9,0}};
    int r = 3,c = 3;
    rep(i,0,r) {
        rep(j,0,c){
            path[i][j] = -1;
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    rep(i,0,r) {
        rep(j,0,c){
            int temp = printPath(i,j,m,r,c);
            ans = max(ans , temp);
            deb2(ans,temp);
        }
    }
    return 0;
}



