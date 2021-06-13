#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define fox(i, k, n, x) for (ll i = k; k < n ? i < n : i > n; k < n ? i += x : i -= x)
#define ll long long
#define deb(x) cout << #x << "=" << x << " "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"


int n,m,o,ans;
  vector<int> a;

  vector<int> nextLargerNodes( vector<int> head) {
        vector<int> a = head;
        
        int j = a[a.size()-1];
        int n =  a.size();
      for(int i = 0 ; i < n-1 ; i++) {
          
          if(a[i] < a[i+1]) {
              int j = i;
              
              while(j < n && a[j-1] >= a[j]) {
                //   if(a[j] < a[j+1] ) break;
                  ++j;
              } 
              
              
              for(int jj = i;jj<j;jj++) {
                  a[jj] = a[j];
              }
              deb2(i,j);
            //   if()
                i = j-1;
            //   if(j < n-1)
            //     if(a[i] < a[j+1]) {

            //     a[j+1] = 0;
            //     i=j+1;
            //     }
            //     else {
            //         a[i]=0;
            //     }
              
          }
          else {
              a[i] = a[i+1];
            //   a[i+1]=0;
            //   i+=1;
          }
      }
      a[n-1] = 0;
        return a;
    }

void solve()
{
    ll k;
    cin>>n;
    rep(i,0,n) cin>>k , a.push_back(k);
    vector<int> v= nextLargerNodes(a);
    for(auto i : v)
    {
        cout<<i<<" ";

    }
    cout<<"\n";

}


int main()
{
    ll t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}





