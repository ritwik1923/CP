#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << "  "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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
const ll me = 100025;
const ll mod = 0x3b9aca07;


ll t, n = 8, c = 3;
ll a[me];//= {174 ,249, 15 ,96 ,163 ,10 ,111 ,100};
// ll a[me] = {10,20,30,40};
int main() {
    cin.tie(0);
    cin >> t;
    while(t --){
        cin >> n;
        for(ll i = 0; i < n; i ++)
            cin >> a[i];
        cin>>c;
        ll  high , mid, best ;
        high=accumulate(a,a+n,0);
        ll low = 0;
        // ll sum[n],s=0;
        rep(i,0,n) {
            low = max(low,a[i]);
        }

        if(n<c) cout<<"-1\n"; else {
        best=-1;
        if(c==1) cout<<high<<"\n";
        else {
        while(low <= high){
            mid = (low + (high - low) / 2);
            // best=-1;
            ll sumupto = 0,student = 0,max_best=LONG_MAX;
            for(int i = 0; i < n && student <= c;i++){
                sumupto+=a[i];

                if(sumupto >= mid) {
                    cout<<sumupto-a[i]<<" ";
                    student ++;
                    max_best = min(max_best,sumupto-a[i]);
                    sumupto = a[i];
                }
            }
            cout<<"\n";
            if(student >= c) {
                cout<<"*";
                best = mid;
                low = mid + 1;
            }
            else
            {

                high = mid - 1;
            }
           deb(student) , deb(low) , deb(high) ,  deb2(mid,best);


            }
        cout << best << endl;
    }
    }
    }

    return 0;
}
