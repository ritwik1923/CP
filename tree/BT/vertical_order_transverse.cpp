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
struct binary_tree {
    ll d;
    binary_tree* left;
    binary_tree* right;
};
binary_tree* create_branch_binary_tree(binary_tree* root,ll x) {
    root= new binary_tree();
    root->d=x;;
    root->left=root->right=NULL;
    return root;
}
void inorder(binary_tree* root) {
if(root==NULL) return ;
inorder(root->left);
cout<<root->d<<" ";
inorder(root->right);
}
void tranver_vertically (binary_tree* root,ll dis,map<ll,vector<binary_tree*>> &m) {
    if(!root) return;
    m[dis].push_back(root);
    tranver_vertically(root->left,dis-1,m);
    tranver_vertically(root->right,dis+1,m);
}
struct binary_tree* vertical_order(binary_tree* root) {
    map<ll,vector<binary_tree*>> m;
    ll dis=0;
    tranver_vertically(root,dis,m);
    for(auto x: m) {
        cout<<x.F<<" : ";
        for(auto s: x.S) {
            cout<<s->d<<" ";
        }
        cout<<"\n";
    }
}

struct binary_tree* create_binary_tree(binary_tree* root) {
    ll x;
    cin>>x;
    if(x==0) return 0;
    if(!root) {
        root=create_branch_binary_tree(root,x);
    }

    root->left=create_binary_tree(root->left);
    root->right=create_binary_tree(root->right);

    return root;
}

int main() {
    binary_tree *root;
    root=NULL;
    root=create_binary_tree(root);
    //inorder(root);
    cout<<"\n";
    vertical_order(root);
	return 0;
}



