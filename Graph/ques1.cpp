
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

class graph {
vector <int , pii > g;
int p,c; // parents and child respectively
public:
void makeGraph(int parents,int children , int weight) {
    g[parents].F = children;
    g[parents].S = weight;
    g[children].F = parents;    
    g[children].S = parents; 
    
}
void print_Adg();
};

void graph:: print_Adg(){
    for(auto x : g) {
        cout<<x.F<<" : ";
        for(auto y : x.S) {
            cout<<"["<<y.F<<"-"<<y.S<<"] ";
        }
        cout<<"\n";
    }
}
int main() {
    int n,e,p,c,w;
    cin>>n>>e;
    graph Graph;
    rep(i,0,e) {
        cin>>p>>c>>w;
        Graph.makeGraph(p,c,w);
    }
    Graph.print_Adg();
    return 0;
}