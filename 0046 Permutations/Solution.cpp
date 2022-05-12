class Solution {

private:
    void recursion(vector<int> nums, int i, int j, vector<vector<int> > &res){
        if(i == j - 1){ //Means we are at the end
            res.push_back(nums);
            return;
        }
        for(int k = i; k < j; k++){
            swap(nums[i], nums[k]);
            recursion(nums, i+1, j, res);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        recursion(nums, 0, nums.size(), res);
        return res;
    }
};