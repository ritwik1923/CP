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
   int ncr[1001][1001];
    int mod = 1000000007;
int _nCr(int n,int r) {
    if(ncr[n][r] == -1)
    /*for combination*/
    ncr[n][r] = (_nCr(n-1,r) + _nCr(n-1,r-1));
    /*for permutation
     P(n, k) = P(n-1, k) + k* P(n-1, k-1)*/
    //ncr[n][r] = (_nCr(n-1,r) + r * _nCr(n-1,r-1));

    return ncr[n][r]%mod;
}
    int nCr(int n, int r){
        // code here
        if(r>n) return 0;
        for(int i = 0 ; i<= n; i++) {
            for(int j = 0; j <= r;j++) {
                ncr[i][j] = -1;
            }
        }
        for(int i = 0 ; i<= n; i++) {
                ncr[i][0] = 1;
                ncr[i][i] = 1;
        }

        return _nCr(n,r);
    }
main() {
cout<<fact(800);
cout<<"\n";cout<<fact(1000);
cout<<"\n";cout<<fact(200);
cout<<"\n";
//rep(i,0,1001) cout<<fac[i]<<" ";
}
