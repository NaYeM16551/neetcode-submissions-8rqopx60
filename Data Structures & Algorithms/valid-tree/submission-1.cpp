class Solution {
    bool dfs(int src,int parent,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathVisited)
    {
        visited[src]=true;
        //pathVisited[src]=true;

        for(auto& child : adj[src])
        {
            

            if(!visited[child])
            {
                auto ans = dfs(child,src,adj,visited,pathVisited);
                if(ans)return true;
            }

            else if(child!=parent)return true;
        }
        //pathVisited[src]=false;
        return false;
        
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false),pathVisited(n,false);

        vector<vector<int>>adj(n);

        for(auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(dfs(0,-1,adj,visited,pathVisited))return false;

        for(int i=0;i<n;++i)
        {
            if(!visited[i])return false;
        }
        return true;
    }
};
