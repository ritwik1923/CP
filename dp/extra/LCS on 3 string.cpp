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
#define Max 100

int dp[Max + 1][Max + 1][Max + 1];
// vector <char> printLCS(string x,string y,int n,int m) {
//     vector <char> s;
//     while(n > 0 && m > 0) {

//         if(x[n-1] == y[m-1]) s.pb(x[n-1])  , n-- ,m--;
//         else if(dp[n - 1][m] - dp[n][m - 1] > 0 )  n--;
//         else m--;
//     }
//     reverse(s.begin(),s.end());
//     return s;
// }

int LCS(string x,string y,string z,int n,int m,int o) {
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= m ;j++) {
            for(int k =  0; k <= o ;k++) {
            dp[i][j][k] = 0;
            }
        }
    }
    for(int i = 1;i < n+1;i++) {
        for(int j =  1; j <= m ;j++) {
            for(int k =  0; k <= o ;k++) {
                if(x[i - 1] == y[j - 1] && x[i - 1] == z[k - 1] && z[k - 1] == y[j - 1] )
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else {
                    /// longest common subset
                    //dp[i][j][k] = 0;
                    /// longest common sequence
                    dp[i][j][k] = max(dp[i - 1][j][k],max(dp[i][j - 1][k],dp[i][j][k - 1]));
                }
            }
        }
    }
    //  for(int i = 0;i < n+1;i++) {
    //      for(int j =  0; j <= m ;j++) {
    //          cout<<dp[i][j]<<" ";
    //      }
    //  cout<<"\n";
    // }
    return dp[n][m][o];
}
int main()
 {
     int t;
     cin>>t;
     while(t--) {
         int n,m,k;
         cin>>n>>m>>k;
         string s1,s2,s3;
         string s4;
         cin>>s1>>s2>>s3;
        //  int b = LCS(s1,s2,n,m);
        //  deb(b);
        // vector <char> s = printLCS(s1,s2,n,m);
        // for(auto i : s)
        //     s4.pb(i) , cout<<i;

         cout<<LCS(s1,s2,s3,n,m,k)<<"\n";
        //   s = printLCS(s4,s3,s4.size(),k);
        // // for(auto i : s)
        // //     cout<<i;
     }
	//code
	return 0;
}
































