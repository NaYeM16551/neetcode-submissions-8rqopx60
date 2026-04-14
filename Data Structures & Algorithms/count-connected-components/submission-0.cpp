class Solution {
    void dfs(int src,vector<vector<int>>&adj,vector<bool>&visited){
        visited[src]=true;

        for(auto& child : adj[src])
        {
            if(!visited[child])
              dfs(child,adj,visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,false);

        int componentCnt = 0;

        for(int i=0;i<n;++i)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
                componentCnt++;

            }
        }
        return componentCnt;
    }
};
