class Solution {
    bool isReachable(vector<vector<int>>& grid,int x,int y,int n,int m,vector<vector<bool>>&visited)
    {
        return x>=0 and x<n and y>=0 and y<m and grid[x][y]>0 and !visited[x][y];
    }
    void bfs(vector<vector<int>>& grid,int x,int y,int n,int m)
    {
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        queue<vector<int>> q;
        q.push({x,y,0});
        visited[x][y]=true;
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
           auto node = q.front();
           q.pop();

           for(auto& d : dir)
           {
            int newX = node[0]+d.first;
            int newY = node[1] + d.second;

            if(isReachable(grid,newX,newY,n,m,visited) and grid[newX][newY]>node[2]+1)
            {
               // cout<<"hello"<<endl;
                visited[newX][newY]=true;
                grid[newX][newY]=node[2]+1;
                q.push({newX,newY,node[2]+1});
            }
           }
        }

    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==0)
                {
                    bfs(grid,i,j,n,m);
                }
            }
        }
        return;
    }
};
