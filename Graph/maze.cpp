
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
void printPath(int x,int y,int m[4][3], int n,int c) {
    if(x < 0 || x >= n || y < 0 || y >= c) return;
    if(m[x][y] == 0 || path[x][y] == 1) return;
    path[x][y] = 1;
    if(x == n-1) {
        //reached to end
        rep(i,0,n) {
            rep(j,0,c) {
                cout<<path[i][j]<<" ";
            }
            cout<<"\n";
        }
            cout<<"\n";
        path[x][y] = 0;
        return;
    }

    //down
    printPath(x+1,y,m,n,c);

    //right
    printPath(x,y+1,m,n,c);

    //up
    printPath(x-1,y,m,n,c);

    //left
    printPath(x,y-1,m,n,c);

    path[x][y] = 0;

}

int main() {

    int m[4][3] = {1,1,1,
                 1,1,1,
                 1,1,1,
                 0,1,0,};
    printPath(0,0,m,4,3);
    return 0;
}


