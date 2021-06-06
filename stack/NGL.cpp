#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define fox(i, k, n, x) for (ll i = k; k < n ? i < n : i > n; k < n ? i += x : i -= x)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define sline(x) getline(cin, x);
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << " "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Endl cout << "\n"
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define Inf 1e9
#define mod 1e9+7
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;


ll MOD(ll,ll);
void doublesetprecision(double,int);
bool isEven(ll);
int gcd(int, int);


int n,m,o,ans,k;
int a[1000000];
void NGL(int arr[], int n)
{
    vi res;
    stack<int> s;
    rep(i, 0, n)
    {
        if (s.size() == 0)
        {
            // s.push(-1);
            res.pb(-1);
        }
        else
        {
            if (arr[i] <= arr[s.top()])
            {
                res.pb(s.top());
            }
            else
            {
                while (arr[s.top()] < arr[i] && s.size() > 0)
                    s.pop();

                if (s.size() == 0)
                {
                    // s.push(-1);
                    res.pb(-1);
                }
                else
                {
                //     deb(i);
                // cout<<s.top()<<" "<<s.size()<<"\n";
                    res.pb(s.top());
                }
            }
        }
        s.push(i);
    }
    for(auto i : res)
    {
        cout<<i+1<<" ";
    }
}


void solve()
{
    
}


int main()
{
    int t = 1;
    // si(t);
    while (t--)
    {
        solve();
        Endl;
    }
    return 0;
}








bool isEven(ll n)
{
    if (n % 2 == 0)
        return 1;
    return 0;
}
void doublesetprecision(double x, int p)
{
    cout << fixed << setprecision(p) << x;
}
ll MOD(ll x, ll M)
{
    x = x % M;
    if( x < 0) x += M;
    return x;
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}