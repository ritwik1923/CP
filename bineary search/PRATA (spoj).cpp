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


ll maxvalue_with_min(ll a[],ll r,ll p) {
    ll low = LONG_MAX;
    rep(i,0,r) low = min(low,a[i]);

    ll res = 0;
    rep(i,1,p+1) res = res + i*low;
    //deb(res);
    return res;
}

ll parata(ll p,ll r,ll a[]) {
    ll  high , mid, best;
    /// high value cant be more than work done by min value person
        high = maxvalue_with_min(a,r,p);
        ///generic (need to be optimum)
        ll low = 0;

        while(low <= high){
            mid = (low + (high - low) / 2);
            ll parata_upto = 0;
           // deb(mid);

            rep(i,0,r) {
                ll s = 0;
                //deb(i) , deb(a[i]);
                for(ll j = 1;parata_upto <= p && s <= mid; j++){
                    parata_upto++;
                    s = s + j*a[i];
                    //cout<<s<<" * "<<j*a[i]<<" - ";
                }
                parata_upto = parata_upto - 1;
                //deb(parata_upto);
                 //   cout<<s<<", ";
                //if(parata_upto >= p) break;
            }
           // deb(parata_upto);
            if(parata_upto < p) {
                low = mid + 1;
            }
            else if(parata_upto >= p) {
                best = mid;
                high = mid - 1;
                //cout<<"*";
            }
            //cout<<"\n";
            }

    return best;

}


int main() {
    int t;
    cin >> t;
    while(t --){
    ll n = 8, c = 3;

        cin >> n;
        cin>>c;
        ll a[c];
        for(ll i = 0; i < c; i ++)
            cin >> a[i];

    cout<<parata(n,c,a)<<"\n";
    }

    return 0;
}

// int main() {
//     // ll p = 10;
//     // ll a[] = {1,2,3,4};
//     // ll n = 4;
//     ll p = 8;
//     ll a[] = {1};
//     ll n = 1;
//     cout<<"\n--------\n"<<parata(p,n,a)<<"\n--------\n";
// }
