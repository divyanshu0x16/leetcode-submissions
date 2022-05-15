class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bit(32, 0);

        for (int i = 0; i < candidates.size(); i++)
        {
            int x = 31;

            while (candidates[i] > 0)
            {
                if( candidates[i] & 1 ){
                    bit[x] = bit[x] + 1;
                }
                candidates[i] = candidates[i] >> 1;
                x--;
            }
        }
        return *max_element(bit.begin(), bit.end());
    }
};