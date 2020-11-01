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

int dp[Max + 1][Max + 1];

    void LCS(string x,string y,int n,int m) {
        for(int i = 0;i < n+1;i++) {
            for(int j =  0; j <= m ;j++) {
                dp[i][j] = 0;
                /*when x is null than we have to insert y char into x*/
                if(i == 0) dp[i][j] = j;
                /*when y is null than we have to insert x char into y*/
                if(j == 0) dp[i][j] = i;
            }
        }
        for(int i = 1;i < n+1;i++) {
            for(int j =  1; j <= m ;j++) {

                if(x[i - 1] != y[j - 1]) // when not same than do take min of 1 + (insertion , deletion or replacement)
                    {
                    // inserting character after i , so i+1th of 1st string is equal to jth char of 2nd string than move to i of 1st and j-1 of 2nd
                    int insertion = 1 + dp[i][j - 1];
                    // delete ith element of x and look for jth char of y in i-1th char of x
                    int deletion = 1 + dp[i - 1][j];
                    // replace ith char of x with jth char of y and go i-1 and j-1 respectively on x & y
                    int replacement = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min(insertion , min(deletion,replacement));
                }
                else // when same do noting do to next element of both the strings
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        for(int i = 0;i < n+1;i++) {
            for(int j =  0; j <= m ;j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    int main() {
        int n,w;
        n = 3;
        w = 10;
        string x = "geeks";
        string y = "gesek";
        LCS(x,y,x.size(),y.size());
        //cout<<knapsack(wt,val,w,n);
    return 0;
    }


