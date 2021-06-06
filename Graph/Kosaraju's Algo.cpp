
#include <bits/stdc++.h>

using namespace std;

// #define V 8

#define pb push_back

//unordered_map<int,vector<int>> adj,rev;
int adj[101], res[101], V;

void DFS1(int i, vector<bool> &visited, stack<int> &mystack)

{

	visited[i] = true;

	for (int j = 0; j < V; j++)

		if (visited[j] == false && adj[i][j] > 0)

			DFS1(j, visited, mystack);

	mystack.push(i);
}

void reverse()

{

	for (int i = 0; i < V; ++i)

	{

		for (int j = 0; j < V; j++)

			if (adj[i][j] > 0)
				res[j][i] = adj[i][j];
	}
}

void DFS2(int i, vector<bool> &visited)

{

	cout << i << " ";

	visited[i] = true;

	for (int j = 0; j < V; j++)

		if (!visited[j])

			DFS2(j, visited);
}

void findSCCs()

{

	stack<int> mystack;

	vector<bool> visited(V, false);

	for (int i = 0; i < V; ++i)

		if (!visited[i])

			DFS1(i, visited, mystack);

	reverse();

	for (int i = 0; i < V; ++i)

		visited[i] = false;

	cout << "Strongly Connected Components are:\n";

	while (!mystack.empty())

	{

		int curr = mystack.top();

		mystack.pop();

		if (visited[curr] == false)
		{

			DFS2(curr, visited);

			cout << "\n";
		}
	}
}

int main()

{
	int t;
	cin >> t;
	while (t--)
	{
		int e, a, b, w;
		cin >> V >> e;
		for (int i = 0; i < e; ++i)
		{
			cin >> a >> b >> w;
			adj[a][b] = w;
		}
		findSCCs();
	}

	return 0;
}

//TIME COMPLEXITY: O(V+E)
