class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; // Initialize ans.
        
        for(int num:nums)
            ans = ans ^ num; // Perform bitwise XOR of ans and num and store the result back in ans.
        
        return ans;
    }
};