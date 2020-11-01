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
//#define near_one (a[i+1][j]==0&&a[i][j+1]==0&&(a[i-1][j]==0&&i-1>=0)&&(a[i][j-1]==0&&j-1>=0))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

int solve(int M[][20],int n,int m) {
    if(n < 0 || m < 0) return 0;

    int len, bre ,dia;
    if(m-1 >= 0) {
        if(M[n][m - 1]) len = 1 + solve(M,n,m-1);
        else len = solve(M,n,m-1);
    }

    if(n-1 >= 0) {
        if(M[n - 1][m]) bre = 1 + solve(M,n - 1,m);
        else bre = solve(M,n - 1,m);
    }

    if(n-1 >= 0 && m-1 >= 0) {
        if(M[n - 1][m - 1]) dia = 1 + solve(M,n - 1,m - 1);
        else dia = solve(M,n - 1,m - 1);
    }

    return min(len,min(bre,dia));

}

int main()
 {
     matrix[][] = {0, 1, 0, 1, 0, 1,
                    1, 0, 1, 0, 1, 0,
                    0, 1, 1, 1, 1, 0,
                    0, 0, 1, 1, 1, 0,
                    1, 1, 1, 1, 1, 1,}
    int n = 5 , m = 6;
    cout<<solve(matrix,n,m);
	//code
	return 0;
}
