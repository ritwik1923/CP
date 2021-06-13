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
#define deb(x) cout << #x << "=" << x << endl
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

int code, p=-1,r,l=0,li=r,u=li,m=0, arr[1000],i=0;
void array_input_recursion(int r)
{
    if(r>0)
        {
            cout<<"  >>>  ";
            cin>>arr[i++];array_input_recursion(--r);
        }
}
void binary_search_recursion(int l,int u,int arr[],int code)
{
   if(l<=u)   {
        m=(u+l)/2;//m=l+(u-l)/2
   if(arr[l]+arr[u]==code){
        deb2(l,u);
        return ;
        }
   else if(arr[l]+arr[u]>code)
        binary_search_recursion(l,m-1,arr,code);
  else
        binary_search_recursion(m+1,u,arr,code);
      }
      else
         cout<<-1;

}
int main()
{
 cin>>r;
   array_input_recursion(r);
    cin>>code;
    binary_search_recursion(0,r-1,arr,code);
   
        cout<<"\n\t\t\tdata is present in pocket  "<<p+1;
    return 0;
}

