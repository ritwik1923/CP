#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// //https://www.boost.org/doc/libs/1_66_0/libs/multiprecision/doc/html/index.html
// using boost::multiprecision::cpp_int;
using namespace std;
#define gc getchar_unlocked
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(ll i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define sline(x)	getline(cin,x);
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

int word_break() {
    string dic,pat;
    int n;
    cin>>n;
     vector<string> dict;
    rep(i,0,n) {
    cin>>dic;
    dict.pb(dic);
    }
     //sline(dic);
     //getline(cin,dic);
     cin>>pat;
     deb2(dic,pat);

     int p=0;
    //  rep(i,0,dic.size()) {
    //    if(dic[i] == ' ') {
    //     dict.pb(dic.substr(p,i-p));
    //     p = i+1;
    //    }
    //  }
    //  dict.pb(dic.substr(p,dic.size()-p));
     reverse(dict.begin(),dict.end());
    int i = pat.size() - 1;
    for(auto it : dict) {
        //cout<<it<<"  "<<it.size()<<"\n";
        if(it[it.size() - 1] == pat[i]) {
            i = i - 1;
            int state = i;
            int j = it.size() - 2;
            while(i >= 0 && j >= 0){
                    if(it[j] != pat[i]) break;
                j--;i--;
            }
            // deb(it);
            // deb2(i,j);
            if(i < 0 && j < 0) {
                // cout<<"Got it"; 
            return 1;}
            else if(j >= 0 ){
                i = state+1;
            }
        }
    }
    // cout<<"not Got :-C";

	//code
	return 0;

}

int main()
 {
     int t;
     cin>>t;
     while(t--) {
      cout<<word_break()<<"\n";
     }
}

// for(int i = *it.size() - 1; i >= 0;i--) {
//                 if()
//             }




