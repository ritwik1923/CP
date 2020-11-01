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

	int dp[1000 + 1];

    int MTFWC(int l,int N, int I,
                       int D, int C)
    {
    if(l > N) return 100000;
    deb(l);
    cout<<"\n";
    if(dp[l] != -1) return dp[l];
    int inserts, del , copys;
    inserts = I + MTFWC(l+1,N,I,D,C);
    del =  D + MTFWC(l-1,N,I,D,C);
    copys =  C + MTFWC(l*2,N,I,D,C);
     deb(inserts) , deb2(del , copys);
    return dp[l] = min(inserts , min(del , copys));


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
        int n,w;
        n = 3;
        w = 10;
        cout<<minTimeForWritingChars(9,1,2,1);
        //cout<<knapsack(wt,val,w,n);
    return 0;
    }


