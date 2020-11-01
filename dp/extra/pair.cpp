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

int dp[Max + 1];

int LCS(int x[],int n,int k) {
    for(int i = 0;i <= n;i++) {
        dp[i]= 1;
    }
    bool vis[n]  = {0};
    map<int,vector<int>> m;
    for(int i = 0;i < n;i++) {
        for(int j =  0; j < i ;j++) {
            if(x[i] - x[j] < k && x[i] - x[j] >= 0) { //
                dp[i] = max(dp[i],dp[j] + 1) ;
                m[i].pb(j);
    }    }
    }
    int sum = 0;
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
        cout<<x[i->F]<<": ";

            for(auto j : i->S) {
                cout<<x[j]<<" ";
            }
        cout<<"\n";
    }
    for (auto i = m.rbegin(); i != m.rend(); ++i) {
        int maxi = 0;
        if(vis[i->F] == false) {
            sum += x[i->F];
            vis[i->F] = 1;
            for(auto j : i->S) {
                if(maxi < j && vis[j] == false) {
                    maxi = max(maxi,j);
                }
            }

        }
        vis[maxi] = 1;
            cout<<"["<<x[i->F]<<" , "<<x[maxi]<<"];";
            sum += x[maxi];
    }
    // deb(sum);
    // int res = 0;
    // for(int i = 0;i < n;i++) {
    //     res = max(res,dp[i]);
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";
    // int index = res;
    //     int sum = 0;
    //     for(int i = n - 1;i >= 0;i--) {
    //         if(index == dp[i])
    //             sum += x[i] , deb(index),index-- , cout<<x[i]<<" "<<i<<"\n";
    //     }
    // printLCS(x,n,m);
    return sum;
}
int main()
 {
	//code

     int t;
     cin>>t;
     while(t--) {
         int n;
         cin>>n;
         int s[n];
         rep(i,0,n) cin>>s[i];
         int k;
         cin>>k;
         sort(s,s+n);
         rep(i,0,n) cout<<s[i]<<" ";
         cout<<"\n";
         cout<<LCS(s,n,k)<<"\n";
     }
	return 0;
}
