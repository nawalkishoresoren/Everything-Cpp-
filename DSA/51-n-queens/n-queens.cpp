class Solution {
public:
    vector<vector<string>>ans;

    bool isvalid(int row,int col,vector<string>&temp,int n)
    {
        for (int i = 0; i < row; i++) {
            if (temp[i][col] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (temp[i][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (temp[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    void solve(int idx, vector<string>&temp,int n)
    {
        if(idx == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int col = 0; col<n ; col++)
        {
            if(isvalid(idx,col,temp,n))
            {
                temp[idx][col] = 'Q';
                solve(idx+1,temp,n);
                temp[idx][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>temp(n,string(n,'.'));
        solve(0,temp,n);
        return ans;
    }
};