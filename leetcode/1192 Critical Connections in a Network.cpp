class Solution {
public:
    vector <int> ar[100001], pb;
    int in[100001],low[100001],vis[100001];
    int timer;
    vector<vector<int>> res;
    void dfs(int node,int par) {
        vis[node] = 1;
        in[node] = low[node] = timer;
        timer++;
        for(int child : ar[node]) {
            if(child == par) continue;
            if(vis[child] == 1) {
                //it is backedge
                low[node] = min(low[node],in[child]);
            }
            else {
                // child is forward edge
                dfs(child,node);
                if(low[child] > in[node])
                    pb.push_back(child) , pb.push_back(node) , res.push_back(pb) , pb.clear();
                low[node] = min(low[node],low[child]);

            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> p;
        pb.clear();
        res.clear();
        timer = 0;
        for(int i = 0 ; i < n ; i ++) {
            ar[i].clear() , vis[i] = 0 , in[i] = 0 , low[i] = 0;
        }
        for(int i = 0 ; i < connections.size() ; i ++) {
            int x,y;
            p=connections[i];
            // x=connections[i][1];
            x = p[0];
            y = p[1];
            p.clear();
            ar[x].push_back(y);
            ar[y].push_back(x);
        }
        dfs(0,-1);
        return res;
    }
};
