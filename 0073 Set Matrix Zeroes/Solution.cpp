class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		set<int> rowZeroes;
		set<int> colZeroes;

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if( matrix[i][j] == 0){
					rowZeroes.insert(i);
					colZeroes.insert(j);
				}

		for (auto &&i : rowZeroes)
			for (int j = 0; j < n; j++)
				matrix[i][j] = 0;

		for (int i = 0; i < m; i++)
			for (auto &&j : colZeroes)
				matrix[i][j] = 0;
    }
};