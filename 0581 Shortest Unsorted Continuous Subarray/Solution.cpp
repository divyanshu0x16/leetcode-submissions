class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int> nums_clone = nums;
        sort(nums_clone.begin(), nums_clone.end());

        int start = nums.size(), end = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != nums_clone[i]){
                start = min(start, i);
                end = max(end, i);
            }
        }
        
        return (end - start >= 0 ? end - start + 1 : 0);
    }
};