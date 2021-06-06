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
    int he[] = {+3,-5,-20};
    int ar[] = {2,-10,5};
int dp[Max + 1][Max + 1];
int pair_friends(int n) {
    if(n <= 0) return 0;

    return 1 + max(pair_friends(n - 1),pair_friends(n - 2));

}
void knapsack(int wt[],int ar[],int w,int a,int n) {
/*
    for(int i = 0;i < 3+1;i++) {
        for(int j =  0; j <= 3 ;j++) {
            dp[i][j] = 0;
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 0;
        }
    }

*/

//   cout<<_knapsack(wt,ar, w,a,n)<<"\n---------\n";
    for(int i = 0;i < n+1;i++) {
        for(int j =  0; j <= n ;j++) {
            if(dp[i][j]!=-1)
            cout<<dp[i][j]<<" ";
        else
            cout<<"_ ";
        }
        cout<<"\n";
    }
}

int main() {
    int n,H,A;
    n = 3;
    H = 2;
    A = 10;
        for(int i = 0;i < 1000+1;i++) {
        for(int j =  0; j <= 1000 ;j++) {
            dp[i][j] = -1;
        }
    }

    cout<<pair_friends(10);
    //cout<<knapsack(wt, w,n);
    return 0;
}




