class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (auto &&i : nums)
        {
            if( i == 0 ) count0++;
            else if( i == 1 ) count1++;
            else count2++;
        }

        vector<int> final(nums.size(), 0);

        for (int i = 0; i < final.size(); i++)
        {
            if( count0 > 0) {
                final[i] = 0;
                count0--;
            }else if( count1 > 0){
                final[i] = 1;
                count1--;
            }else{
                final[i] = 2;
                count2--;
            }
        }
        nums = final;
        
    }
};