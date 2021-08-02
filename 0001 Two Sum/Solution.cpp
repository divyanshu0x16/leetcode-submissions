class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> doesExist;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            int rem = target - curr;
            if( rem != curr ) doesExist[curr] = i;
            if( (doesExist.find(rem) != doesExist.end()) and ( doesExist[rem] != i)){
                ans.push_back(i);
                ans.push_back(doesExist[rem]);
                break;
            }      
            doesExist[curr] = i;   
        }
        return ans;
    }
};