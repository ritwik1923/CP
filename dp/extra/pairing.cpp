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
    if(n<=0) return 0;
    if(n == 1) return x[0];

    int pairing , not_pairing;
    if(n > 0 && n-1 > 0) {
        if(x[n-1] - x[n-2] < k )
            pairing = x[n-1] + x[n-2] + LCS(x,n-2,k);
        else
            not_pairing = LCS(x,n-1,k);
        return max(pairing,not_pairing);

    }
    //return x[n-1] + x[n-2];

}
int main()
 {
	//code

     int t;
    //  cin>>t;
    t=1;
     while(t--) {
         int n = 7;
        //  cin>>n;
         int s[n] = {3, 5, 10, 15, 17, 12, 9};
        //  rep(i,0,n) cin>>s[i];
         int k = 4;
        //  cin>>k;
        //  sort(s,s+n);
        //  rep(i,0,n) cout<<s[i]<<" ";
        //  cout<<"\n";
         cout<<LCS(s,n,k)<<"\n";
     }
	return 0;
}

