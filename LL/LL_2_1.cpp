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
const ll me = 100025;
const ll mod = 0x3b9aca07;

// A complete working C++ program to demonstrate 
// all insertion methods on Linked List 


// A linked list node 
class Node 
{ 
	public: 
	ll data; 
	Node *next; 
}; 

/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push(Node** head_ref, ll new_data) 
{ 
	/* 1. allocate node */
	Node* new_node = new Node(); 

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref); 

	/* 4. move the head to poll to the new node */
	(*head_ref) = new_node; 
} 

/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(Node* prev_node, ll new_data) 
{ 
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) 
	{ 
		cout<<"the given previous node cannot be NULL"; 
		return; 
	} 

	/* 2. allocate new node */
	Node* new_node = new Node(); 

	/* 3. put in the data */
	new_node->data = new_data; 

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next; 

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node; 
} 

/* Given a reference (pointer to pointer) to the head 
of a list and an int, appends a new node at the end */
void append(Node** head_ref, ll new_data) 
{ 
	/* 1. allocate node */
	Node* new_node = new Node(); 

	Node *last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. This new node is going to be 
	the last node, so make next of 
	it as NULL*/
	new_node->next = NULL; 

	/* 4. If the Linked List is empty, 
	then make the new node as head */
	if (*head_ref == NULL) 
	{ 
		*head_ref = new_node; 
		return; 
	} 

	/* 5. Else traverse till the last node */
	while (last->next != NULL) 
		last = last->next; 

	/* 6. Change the next of last node */
	last->next = new_node; 
	return; 
} 

// This function prints contents of 
// linked list starting from head 
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<<node->data<<" "; 
		node = node->next; 
	} 
} 
void printList_particular_from_end(Node *node, ll k) 
{ 
    // //deb(n);
    ll p=n-k,i=0;
	while (node != NULL) 
	{ 
        if(i==p)
		cout<<node->data<<" "; 
		node = node->next; i++;
	} 
} 

/* Driver code*/
int main() 
{ 
    ll t;
    cin>>t;
    while(t--){
	/* Start with the empty list */
    ll n,k,i=0,x;
    cin>>n>>k;
    Node* head = NULL; 
    while(i<n) {
        cin>>x;
        append(&head, x);i++;
    }
	printList_particular_from_end(head,k);
	
	cout<<"\n";
	 
	}
	return 0; 
} 


// This code is contributed by rathbhupendra 
