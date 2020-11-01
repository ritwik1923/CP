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

int _LCS(int x[],int n) {
    if(n <= 0) return 0;

    if(x[n-1] > x[n - 2])
        return max(1 + _LCS(x,n-1),_LCS(x,n-1));
    else
        return _LCS(x,n-1);
}

int LCS(int x[],int n) {

    _LCS(x,n);
    return dp[n];
}
int main()
 {
	//code

     int t;
     //cin>>t;
     t = 1;
     while(t--) {
         int n = 6;
         //cin>>n;
         int s[n] = {5 ,8 ,3 ,7 ,9 ,1};
         //rep(i,0,n) cin>>s[i];
         cout<<LCS(s,n)<<"\n";
     }
	return 0;
}
