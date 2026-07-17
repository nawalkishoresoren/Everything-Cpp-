class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    bool isvalid(int x,int y,int idx,vector<vector<char>>& board,string& word)
    {
        if(x>=0 and x<board.size() and y>=0 and y<board[0].size() and board[x][y] == word[idx])
            return true;
        return false;

    }
    bool dfs(int x,int y,int idx,vector<vector<char>>& board, string& word)
    {
        if(idx == word.size()-1)
            return true;
        board[x][y] = '.';
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isvalid(nx,ny,idx+1,board,word))
            {
                if(dfs(nx, ny, idx+1, board, word))
                    return true;
            }
        }
        board[x][y] = word[idx];
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                    if(dfs(i,j,0,board,word))
                        return true;
            }
        }
        return false;;
    }
};