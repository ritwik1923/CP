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

int MCM(string str , int i , int j) {
    if(i > j) return 0;
    if(i == j ) {
        if(str[i] == 'T') {
            cout<<"@";
            return 1;
        }
        else {
            cout<<"+";
            return 0;
        }

    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int res = 0;
    for(int k = i ; k < j ; k = k + 2) {
        int Tans = 0  , leftT = 0, rightT = 0, leftF = 0, rightF = 0;
        if( MCM(str , i , k) == 0)
                leftF++;
        if( MCM(str , i , k) == 1)
                leftT++;
        if( MCM(str , i , k) == 0)
                rightF++;
        if( MCM(str , i , k) == 1)
                rightT++;
        if(str[k+1] == '|') {
          if(right == 1 || left == 1)
                Tans +=1;
        }
        else if(str[k+1] == '&') {
          tans = rightT*leftT;

        }
        else if(str[k+1] == '^') {
          if((right == 1 && left == 0) || (right == 1 && left == 1))
                Tans +=1;
        }

        cout<<"l: "<<left<<" r: "<<right<<" Tans: "<<Tans<<" - ";
        res = max(res,Tans);

    }
    cout<<res<<" i: "<<i<<" j: "<<j<<"\n";
    return dp[i][j] = res;
}

/*You are required to complete below method */
int countPS(string str)
{
    for(int i = 0;i <= str.size() ;i++) {
        for(int j =  0; j <= str.size() ;j++) {
            dp[i][j] = -1;
        }
    }
    return MCM(str , 0 , str.size() - 1);
   //Your code here
}

int main() {
    int t;
    //cin>>t;
    t = 1;
    while(t--) {
        string x = "T|T&F^T" ;
        //cin>>x;
        cout<<countPS(x);
        //cout<<knapsack(wt,val,w,n);
    }
    return 0;
}


