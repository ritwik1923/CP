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
const ll me = 100025;
const ll mod = 0x3b9aca07;
bool isbraketopen(char c) {
    if(c=='['||c=='{'||c=='(')
    return true;
    return false;
}
bool isoperatand(char c) {
    if((c>='a'&&c<='a'+25)||(c>='A'&&c<='A'+25))
    return true;
    return false;
}
bool isoperator(char c) {
    if(c=='^'||c=='*'||c=='/'||c=='+'||c=='-')
    return true;
    return false;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	     stack <char> c;
	    for(int i=0;i<s.size();i++) {
	        if(isbraketopen(s[i])){
	            c.push(s[i]);
	        }
	        else if(isoperatand(s[i])){
	            cout<<s[i]<<" ";
	        }
	        else if(isoperator(s[i])){
	            c.push(s[i]);
	        }
	        else  {
	           
	            while(((c.top()!='['&&s[i]==']')||(c.top()!='{'&&s[i]=='}')||(c.top()!='('&&s[i]==')')))
	            cout<<c.top();
	            c.pop();
	        }
	    }
	}
	return 0;
}