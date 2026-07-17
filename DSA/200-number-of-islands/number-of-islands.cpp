class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isvalid(int nx, int ny, vector<vector<char>>& grid)
    {
        if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size() and grid[nx][ny]=='1')
            return true;
        return false;
    }
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        grid[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isvalid(nx,ny,grid))
            {
                dfs(nx,ny,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    count++;
                }
                    
            }
        }
        return count;
    }
};