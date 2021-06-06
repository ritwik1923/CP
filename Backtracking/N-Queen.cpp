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
#define pl2(x,y)	printf("%lld %lld\n",x,y)
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
map<int,vi> m;
static int f=0;
bool valid(int x,int y,int n) {
    if(x <= 0 ||x > n || y <= 0 || y > n) return false;
    return true;
}

bool notinattrack(int board[][20],int x,int y,int n) {
rep(i,1,n+1) {if(board[x][i] == 1) return false;}
rep(i,1,n+1) {if(board[i][y] == 1) return false;}
int ax=x,ay=y;
while(valid(ax,ay,n)) {
   if(board[ax][ay] == 1) return false;
   ax++;ay++;
}
 ax=x,ay=y;
while( valid(ax,ay,n)) {
   if(board[ax][ay] == 1) return false;
   ax--;ay--;
}
 ax=x,ay=y;
while((ax+ay)== x+y && valid(ax,ay,n)) {
   if(board[ax][ay] == 1) return false;
   ax++;ay--;
}
 ax=x,ay=y;
while((ax+ay)== x+y && valid(ax,ay,n)) {
   if(board[ax][ay] == 1) return false;
   ax--;ay++;
}
return true;
}
void findpath(int board[][20], int n, int x,int y) {
    if(!notinattrack(board,x,y,n)) return;// false;
board[x][y] = 1;
if(x == n){
    //board[x][y] = 1;
     rep(i,1,n+1) {
     rep(j,1,n+1) {
         if(board[i][j] == 1) 
         m[f].pb(j);
        // cout<<board[i][j]<<" ";
    }
   
       // cout<<"\n";
   } f++;
   // cout<<"\n";
    return;
}

rep(i,1,n+1)
{
    findpath(board,n,x+1,i);
board[x+1][i] = 0;
}
board[x][y] = 0;
}

void findpath(int board[][20], int n) {
rep(i,1,n+1){

 findpath(board,n,1,i);board[1][i] = 0;
 }

}
int main() {
int t;
cin>>t;
while(t--) {
    m.clear();
    
int n;
cin>>n;

int board[20][20] = {0};

findpath(board,n);
if(m.size()!=0) {
    for(auto i: m) {
    cout<<"[";
    for(auto j : i.S) {
        cout<<j<<" ";
    }
    cout<<"] ";
}
}
else cout<<-1;
cout<<" \n";

}
return 0;
}

