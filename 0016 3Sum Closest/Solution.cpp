class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            int lo = i+1;
            int hi = nums.size()-1;

            while (lo < hi)
            {
                int sum = nums[i]+nums[lo]+nums[hi];

                if( abs(target-sum) < abs(diff))
                    diff = target-sum;

                if(sum < target) lo++;
                else hi--;
            }
            
            if(diff == 0) break;
        }
        
        return target-diff;
    }
};