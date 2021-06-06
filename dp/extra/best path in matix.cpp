
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
int path[1000][1000];
int dp[1001][1001];
int printPath(int x,int y,int m[][26], int n,int c) {
    if(x < 0 || x >= n || y < 0 || y >= c) return 0;
    if(m[x][y] == 0 ) return 0;
    if(path[x][y] == 1) return 0;
    // if(dp[x][y] != -1) return dp[x][y];
    path[x][y] = 1;
    int down = 0 , right = 0, up = 0 , left = 0;
    //down
    down = printPath(x+1,y,m,n,c);

    //right
    right = printPath(x,y+1,m,n,c);

    //up
    up = printPath(x-1,y,m,n,c);

    //left
    left = printPath(x,y-1,m,n,c);

    path[x][y] = 0;
    cout<<m[x][y]<<"  " , deb(x) , deb(y) ,deb(down) , deb(up) , deb2(right,left);
    return  m[x][y] + max(down,max(right,max(up,left)));
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


