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
//typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
//typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
//typedef vector<vl>		vvl;
    ll graph[1001][1001];
    vi ar[10000];
    int in[101],low[101],vis[101];
    int timer;

    void dfs(int node,int par) {
        vis[node] = 1;
        cout<<node<<"->";
        in[node] = low[node] = timer;

        for(int child : ar[node]) {
            if(vis[child] == 0) {
                timer++;
                    // child is forward edge
                deb2(child,node);
                dfs(child,node);
                low[node] = min(low[node],low[child]);
                if(low[child] > in[node])
                    cout<<"bridge "<<child<<" - "<<node<<"\n";
            }
            else if(child != par){
                //it is backedge
                low[node] = min(low[node],in[child]);

            }
        }
    }

    int main() {
        int x,y,n,m;

        cin>>n>>m;
        rep(i,0,m) {
            cin>>x>>y;
            ar[x].pb(y);
            ar[y].pb(x);
        }
        rep(j,1,n+1) {
            cout<<j<<" : ";
            for(int i : ar[j])
            cout<<i<<"->";
            cout<<"\n";
        }
        rep(i,1,n+1){
            if(vis[i] == 0)
                dfs(i,-1);
        }
        rep(j,1,n+1) {
            cout<<j<<" : "<<low[j]<<" | ";
            for(int i : ar[j])
            cout<<"("<<i<<","<<low[i]<<") ";
            cout<<"\n";
        }
        return 0;
    }
