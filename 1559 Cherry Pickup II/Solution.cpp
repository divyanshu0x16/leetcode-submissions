class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dpCache(m, vector<vector<int>>(n, vector<int>(n)));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    dpCache[i][j][k] = -1;
        
        return dp(0, 0, n-1, grid, dpCache);
    }

    int dp(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dpCache){
        
        if(col1 < 0 or col1 >= grid[0].size() or col2 < 0 or col2 >= grid[0].size())
            return 0;

        //First we check cache
        if(dpCache[row][col1][col2] != -1)
            return dpCache[row][col1][col2];

        //Deal with current cell
        int result = 0;
        result += grid[row][col1];
        if(col1 != col2)
            result += grid[row][col2];

        //Transition
        if(row != grid.size() - 1){
            int maximum = 0;
            for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++)
                for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++)
                    maximum = max(maximum, dp(row+1, newCol1, newCol2, grid, dpCache));

            result += maximum;
        }

        dpCache[row][col1][col2] = result;
        return result;
    }
};