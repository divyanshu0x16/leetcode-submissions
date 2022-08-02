class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri)
		{
			mid = le + (ri-le)/2;
			int num = 0;
			for (int i = 0; i < n; i++) // Important: For Loop, to find the current position of mid in matrix
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k)
			{
				le = mid + 1; //Since our current num is less than k, we have to increase this num, i.e. to k find the kth smallest element, 'mid' must higher. Hence increase left
			}
			else
			{
				ri = mid;
			}
		}
		return le;
	}

};