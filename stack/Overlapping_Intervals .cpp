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

bool cmp(const pair<int,int> &f,const pair<int,int> &s) {
    return(f.second<s.second);
    
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int f[n],s[n];
        rep(i,0,n) {
            cin>>f[i]>>s[i];
        }
	    vector< pair <int,int> > p;
	    for(int i=0;i<n;i++) {
	        int x;
	        p.push_back(make_pair(f[i],s[i]));
	        }
	    sort(p.begin(),p.end(),cmp);
        
            rep(i,0,n) {
            cout<<p[i].F<<"   "<<p[i].S<<"\n";
        ll first,second;
        stack <ll> ss;
        vector< pair <int,int> > v;
        rep(i,0,n) {
           if(ss.size()==0) {
               ss.push(p[i].S);
               first=p[i].F;
               second=p[i].S;
           }
           else {
               if(ss.top()>=p[i].F){
                    ss.pop();
                ss.push(p[i].S);
                    second=p[i].S;
                    //v.push_back(make_pair(f,s[i]));
               }
               else {
                ss.pop();
                
                //ss.push(p[i].S);
                    v.push_back(make_pair(first,second));
                first=p[i].F;
                second=p[i].S;
                ss.push(p[i].S);
                   // first=p[i].F;
               } 
                
                    
            }
            rep(i,0,v.size()) {
            cout<<v[i].F<<"   "<<v[i].S<<"\n";
        }
        }
	}
	return 0;
}