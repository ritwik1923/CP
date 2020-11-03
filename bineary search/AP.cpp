#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//https://www.boost.org/doc/libs/1_66_0/libs/multiprecision/doc/html/index.html
//using boost::multiprecision::cpp_int;
using namespace std;

#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long

ll range = 1000000000;

bool binary_search(ll ind,ll key, ll cd) {
  ll low = -1*range, high =range, mid, best =0;
  ll low1 = -1*range, high1 = range , mid1;
  if(key<0||ind<0||cd<0) high+=abs(ind);
  while(low <= high || low1 <= high1) { //||(key<=0)&&cd<0
	  mid = low + (high - low)/2;
	  mid1 = low1 + (high1 - low1)/2;
	  if(((ind + (mid * cd)) == key )) {
		  cout<< mid <<" ";
	  return true;}
	  else if((ind + (mid * cd)) < (key))
	  {
		  low = mid+1;
	  }
	  else {
	  		high = mid - 1;
	  }
	  if(((ind + (mid1 * cd)) == key)) {
		  cout<< mid1 <<"* ";
	  return true;}
	  else if((ind + (mid1 * cd)) < (key))
	  {
		  high1 = mid1 - 1;
	  }
	  else {
	  		low1 = mid1 + 1;
	  }
	  deb2(mid,mid1);
// 	  cout<<ind + mid * cd <<"  "<<mid <<" ";
// 	  deb2(low,high);
  }

  return false;

}
// int main() {

// ll t;
// cin>>t;
// while(t--) {
// 	ll a,b,c;
// 	cin>>a>>b>>c;
// 	ll x=(b-a);//cout<<x<<" ";

//
// }

//     return 0;
// }

int main() {
	// ll A = 989140430;
	// ll B = 731276607;
	// ll C =  -36837689;

	ll A = -10;
	ll B = -22;
	ll C = -2;
	if(binary_search(A,B,C))
	 cout<<1;
	else cout<<0;
	cout<<"\n";

}
