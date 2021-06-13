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
vector<ll> NGL(ll a[],ll n) {
        vector<ll> ngl;
        stack <ll> s;
    rep(i,0,n) {
            if(s.empty()) {
                
                ngl.push_back(-1);
            }
            else {
                if(a[s.top()]>a[i]) {
                ngl.push_back(s.top());
            }
            else if(a[s.top()]<=a[i]) {
                while(s.size()>0&&a[s.top()]<=a[i]) s.pop();
                if(s.empty()) ngl.push_back(-1);
            else ngl.push_back(s.top());
            }
                
            }
        s.push(i);
            
        }
        return ngl;
}

vector<ll> NGR(ll a[],ll n) {
        vector<ll> ngr;
        stack <ll> s;

        Fo(i,n-1,-1) {
            if(s.empty()) {
                
                ngr.push_back(n);
            }
            else {
                if(a[s.top()]>a[i]) {
                ngr.push_back(s.top());
            }
            else if(a[s.top()]<=a[i]) {
                while(s.size()>0&&a[s.top()]<=a[i]) s.pop();
                if(s.empty()) ngr.push_back(n);
            else ngr.push_back(s.top());
            }
                
            }
        s.push(i);
            
        }
        reverse(ngr.begin(),ngr.end());
        

        return ngr;
}

int main() {
    ll n,q;
    cin>>n>>q;
    ll a[n],p[n];
    rep(i,0,n) cin>>p[i];
    rep(i,0,n) cin>>a[i];
        vector<ll> ngl = NGL(p,n);
        vector<ll> ngr = NGR(p,n);
        rep(i,0,n) cout<<ngl[i]<<" ";
        cout<<"\n";
        rep(i,0,n) cout<<ngr[i]<<" ";
        cout<<"\n";
        while(q--) {
            ll Q,b,k;
            cin>>Q>>b>>k;
            if(Q==1) {
                a[b-1] =k;
            }
            b--;k--;
            ll sum=0;
            if(Q==2) {
                if(p[b]<=p[k]) {
                    sum=-1;
                }
                else {
                    //going left
                    if(p[b]>p[k]) {
                        if(b>k) { //rtol ngr
                            ll i = k;
                        while(p[i]<=p[b]) {
                            sum+=a[i];
                            i=ngl[i];
                        }
                       cout<<sum<<"*\n";  
                    }
                    else if(b<k) { //rtol ngr
                            ll i = b;
                        while(p[i]<=p[b]) {
                            sum+=a[i];
                            i=ngr[i];
                        }
                       cout<<sum<<"*\n";  
                    }
                }
               // cout<<sum<<"\n";
            }
            
        }
    return 0;
    
}
