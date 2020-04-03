class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_current; int max_global;
        max_global = nums[0];
        max_current = nums[0];
        for ( int i = 1; i <= nums.size() - 1; i++ ){
            max_current = max( nums[i], max_current + nums[i]);
            if ( max_current > max_global ){
                max_global = max_current;
            }
        }
        return max_global;
    }
};