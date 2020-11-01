#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define pl2(x, y) printf("%lld %lld\n", x, y)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << " "
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, char> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;

struct node
{
	int data;
	char cha;
	node *left;
	node *right;
};
node *Newnode(int a, char c)
{
	struct node *temp = new node;
	temp->data = a;
	temp->cha = c;
	//temp->left = NULL;
	//temp->right = NULL;
	return temp;
}
node *Mergenode(node *temp, node *c1, node *c2)
{
	//     struct node *temp =  new node;
	temp = new node();
	temp->data = c1->data + c2->data;
	temp->cha = 0;
	if (c1->data > c2->data)
		temp->right = c1, temp->right = c1;
	else
		temp->right = c2, temp->left = c1;
	return temp;
}
// Function to Insert Node in a Binary Search Tree
node *Insert(node *root, int data, char c)
{
	if (root == NULL)
	{
		root = new node();
		root->data = data;
		root->cha = c;
		root->left = root->right = NULL;
	}
	else if (data > root->data)
		root->left = Insert(root->left, data, c);
	else
		root->right = Insert(root->right, data, c);
	return root;
}
vector<int> v;
void print(node *root, string s = "")
{
	if (root == NULL)
		return;
	//v.pb(0);
	print(root->left, s + '0');
	//if(root->cha <= 'a'+25 && root->cha >= 'a'){
	if (root->left == NULL && root->right == NULL)
	{
		// cout<<root->cha<<" : "<<root->data<<" = ";
		cout << s;
		cout << " ";
		// cout<<"\n ";
	}

	//}
	//v.pop_back();
	//v.pb(1);
	print(root->right, s + '1');
	//v.pop_back();
}

struct HEC
{
	char C;
	int freq;
};

bool comp(HEC a, HEC b)
{
	return (a.freq < b.freq);
}
struct Comp
{
	bool operator()(node *a, node *b)
	{
		if (a->data == b->data)
			return (a->cha <= b->cha);
		return (a->data > b->data);
	}
};

int main()
{
	//code
	int t = 1;
	// cin>>t;
	while (t--)
	{
		string s = "qwertyuiopasdfghjkl";
		// cin>>s;
		int n = s.size();
		priority_queue<node *, vector<node *>, Comp> pq;
		int f[n] = {5, 6, 9, 11, 14, 15, 31, 32, 35, 37, 48, 59, 66, 82, 89, 90, 91, 94, 98};
		node *t;
		HEC sf[n];
		rep(i, 0, n)
		{
			// cin>>f[i];
			sf[i].C = s[i];
			sf[i].freq = f[i];
		}
		sort(sf, sf + n, comp);
		rep(i, 0, n)
		{
			t = Newnode(sf[i].freq, sf[i].C);
			t->left = NULL;
			t->right = NULL;
			pq.push(t);
		}

		node *root = NULL;
		while (pq.size() > 1)
		{
			int a, b;
			char aC, bC;
			node *t0, *t1;
			t0 = pq.top();
			a = pq.top()->data, aC = pq.top()->cha, pq.pop();

			t1 = pq.top();
			b = pq.top()->data, bC = pq.top()->cha, pq.pop();
			// deb2(a,b);
			// deb2(aC,bC);
			// cout<<aC<<"="<<a<<":"<<bC<<"="<<b<<"\n";
			// deb2(a,b);
			//root = Insert(root,a+b,0);
			root = Newnode(a + b, 0);
			if (a < b)
			{
				root->left = t0;
				root->right = t1;
			}
			else
			{
				root->left = t1;
				root->right = t0;
			}
			//     print(root);
			// cout<<"---\n";
			pq.push(root);
		}
		//vector<int> v;
		print(root);
		cout << "\n";
	}
	return 0;
}
