class Solution {
public:
    vector<vector<int>> generate(int numRows) {

		if( numRows == 1 ) {
			vector<vector<int> > pascalTraingle = {{1}};
			return pascalTraingle;
		}

		if( numRows == 2 ){
			vector<vector<int> > pascalTraingle = {{1}, {1, 1}};
			return pascalTraingle;
		}
        
		vector<vector<int> > pascalTraingle = {{1}, {1, 1}};

		int currRows = 2;

		while (currRows < numRows)
		{
			vector<int> currentRow;
			vector<int> previousRow = pascalTraingle[pascalTraingle.size()-1];
			currentRow.push_back(1);

			while (currentRow.size() < previousRow.size())
				for (int i = 0; i <= previousRow.size() - 2; i++)
					currentRow.push_back( previousRow[i] + previousRow[i+1] );
			
			currentRow.push_back(1);
			currRows++;

			pascalTraingle.push_back(currentRow);
		}
		
		return pascalTraingle;
    }
};