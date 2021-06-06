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

unordered_map <string,int> dp;
int life(int A,int H,int choice) {
    if( A <= 0 || H <= 0) return 0; //vis[choice] == 1 ||
    string key = to_string(A) + " " + to_string(H) + " " + to_string(choice);

    if(dp.find(key) != dp.end()) {
        // deb(key) ; 
    return dp[key];}
    if(A+ar[choice]>0 && H + he[choice]>0) {
        int takeL = life(A+ar[choice] , H + he[choice],(choice + 1)%3);
        // deb(takeL) , cout<<"C: "<<(choice + 1)%3<<" A: "<<A+ar[choice]<<" H: "<<H + he[choice]<<"\n";
        int takeR = life(A+ar[choice] , H + he[choice],(choice + 2)%3);
        // deb(takeR) , cout<<"C: "<<(choice + 2)%3<<" A: "<<A+ar[choice]<<" H: "<<H + he[choice]<<"\n";

        // deb(key);
        return dp[key] = 1 + max(takeL,takeR);
    }
    else
        return dp[key] = 0;

}

int main() {
    int n,H,A;
    cin>>n;
    while(n--) {
        cin>>H>>A;
    // for(int i = 0;i < 1000+1;i++) {
    //     for(int j =  0; j <= 1000 ;j++) {
    //             for(int k = 0; k <= 2; k++)
    //         dp[i][j][k] = -1;

    //     }
    // }
    dp.clear();

    cout<<life(A,H,0)<<"\n";
    }//cout<<knapsack(wt, w,n);
    return 0;
}
