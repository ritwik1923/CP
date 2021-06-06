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
#define pl2(x,y)	printf("%lld %lld\n",x,y)
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
int path[1000][1000];
int ans = 0;
int MAX = 101;
int dp[1001][1001];
int printPath(int x,int y,int m[][50], int n) {
    if(x < 0 || x >= n || y < 0 || y >= n) return 0;
    if(m[x][y] == 0 || path[x][y] == 1) return 0;

    path[x][y] = 1;
    if(x == (n-1)) {
        //reached to end
        path[x][y] = 0;
        return dp[x][y] = m[x][y];
    }
    if(dp[x][y] != -1) return dp[x][y];
    //down
    int move1 = printPath(x+1,y,m,n);

    //right
    int move2 = printPath(x+1,y+1,m,n);

    //up
    //left
    int move3 = printPath(x+1,y-1,m,n);


    path[x][y] = 0;
    cout<<m[x][y]<<"  " , deb(x) , deb(y) ,deb(move1) , deb2(move2,move3);
    return dp[x][y] = m[x][y] + max(move1,max(move2,move3));


}

main() {
    int N = 3;
    int m[][50] = {{348, 391,562},
                    {618, 193,869},
                    {68, 13,69}};

    for(int i = 0;i < N; i++) {
        for(int j = 0 ; j < N ; j++) {
            dp[i][j] = -1;
        }
    }

    for(int i = 0;i < N; i++) {
    cout<<printPath(0,i,m,N)<<"\n";
    }
    cout<<ans;
}
