class Solution {
public:
int m,n;
queue<pair<int,int>> q;

    void rotting(vector<vector<int>>&grid,int u,int v, int k)
    {
        if(u<0 || u>=m || v<0 || v>=n) return;

        if(grid[u][v] == 1)
        {
            grid[u][v] = k+1;
            q.push({u,v});
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
            }
        }

        while(!q.empty())
        {
            auto[u,v] = q.front();
            q.pop();
            rotting(grid,u-1,v,grid[u][v]);
            rotting(grid,u,v-1,grid[u][v]);
            rotting(grid,u+1,v,grid[u][v]);
            rotting(grid,u,v+1,grid[u][v]);
        }

        int answer=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) return -1;
                answer=max(grid[i][j],answer);
            }
        }
        return max(answer-2,0);

    }
};
