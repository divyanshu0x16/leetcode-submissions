class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector< vector < int > > triangle;

        vector<int> hello; hello.push_back(1);
        triangle.push_back(hello);

        for (int i = 1; i < rowIndex+1; i++)
        {
            vector<int> row;
            vector<int> prevRow = triangle[i-1];

            row.push_back(1);

            for (int j = 1; j < i; j++)
                row.push_back( prevRow[j-1] + prevRow[j] );

            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle[rowIndex];
    }
};