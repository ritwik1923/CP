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
int dp[1001][1001];

bool pallindrom(string str , int i , int j) {
    while(i<=j) {
        if(str[i] != str[j]) return 0;
        i++ , j--;
    }
    return 1;
}

int MCM(string str , int i , int j, char whatBool) {
    if(i > j) return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(i == j ) {
        if(str[i] == whatBool) {
            cout<<"@";
            return 1;
        }
        else {
            cout<<"+";
            return 0;
        }

    }


    int ans = 0;
    for(int k = i ; k < j ; k = k + 2) {
        int LT = MCM(str,i,k,'T');
        int LF = MCM(str,i,k,'F');
        int RT = MCM(str,k+2,j,'T');
        int RF = MCM(str,k+2,j,'F');

        if(str[k+1] == '&') {
                if(whatBool == 'T') {
                    ans += LT * RT;
                }
                else {
                    ans += (LT * RF) + (LF * RT) + (LF * RF);
                }
        }
        else if(str[k+1] == '|') {
            if(whatBool == 'T') {
                    ans += (LT * RF) + (LF * RT) + (LT * RT);
                }
                else {
                    ans += (LF * RF);
                }
        }
        else if(str[k+1] == '^') {
            if(whatBool == 'T') {
                    ans +=  (LT * RF) + (LF * RT);
                }
                else {
                    ans += (LT * RT) + (LF * RF);
                }
        }
        deb(LF) , deb(LT) , deb2(RF,RT);

    }
    cout<<ans<<" i: "<<i<<" j: "<<j<<"\n";
    return dp[i][j] = ans;
}

/*You are required to complete below method */
int countPS(string str)
{
    for(int i = 0;i <= str.size() ;i++) {
        for(int j =  0; j <= str.size() ;j++) {
            dp[i][j] = -1;
        }
    }
    return (MCM(str , 0 , str.size() - 1,1) + 1);
   //Your code here
}

int main() {
    int t;
    //cin>>t;
    t = 1;
    while(t--) {
        string x = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F" ;
        //cin>>x;
        cout<<countPS(x);
        //cout<<knapsack(wt,val,w,n);
    }
    return 0;
}


