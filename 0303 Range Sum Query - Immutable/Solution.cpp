class NumArray {
public:
    NumArray(vector<int>& nums) {
        accu.push_back(0);
        for(int num: nums)
            accu.push_back(accu.back() + num);
    }
    
    int sumRange(int left, int right) {
        return accu[right + 1] - accu[left];
    }

    private:
        vector<int> accu;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */