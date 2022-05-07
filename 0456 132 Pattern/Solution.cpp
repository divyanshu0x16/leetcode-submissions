/*
https://assets.leetcode.com/users/images/5184cab5-9a65-44a6-8a3c-12bb2635362a_1651887812.8684826.png
*/


class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int s3 = INT_MIN;

        stack<int> st;

        for (int i = nums.size()-1; i >= 0; i--)
        {
            if( nums[i] < s3 ) return true;

            else while ( !st.empty() and nums[i] > st.top())
            {
                s3 = st.top(); st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};