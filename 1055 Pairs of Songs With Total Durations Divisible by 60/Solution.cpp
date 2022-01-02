class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> array(60, 0);
        
        for(int i = 0; i < time.size(); i++){
            int rem = time[i]%60;
            
            if(!rem) count += array[0];
            else count += array[60-rem];
            
            array[rem]++;
        }
        
        return count;
        
    }
};