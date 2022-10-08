class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int msf = INT_MIN;
        int meh = 0;
        
        int start = 0, end;
        
        for(int i = 0; i < nums.size(); i++){
            meh += nums[i];
            
            if( meh > msf){
                msf = meh;
            }
            
            if( meh < 0 ){
                meh = 0;
            }
        }
        
        return msf;
    }
};