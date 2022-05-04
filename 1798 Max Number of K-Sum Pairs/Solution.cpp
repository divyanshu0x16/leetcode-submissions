class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //Initialize a freq array
        map<int, int> freq;

        //Set Frequencies
        for (auto &&i : nums)
            freq[i]++;
        

        int ans = 0;

        //Iterate through the map
        for(auto itr : freq){
            int i = itr.first, j = k - itr.first;

            if(i == j){
                if(freq[i] < 1)
                    continue;
                else
                    ans += freq[i]/2;
            }else if( freq.find(k-i) != freq.end() ){
                ans += min(freq[i], freq[k-i]);
                freq[i] = 0;
                freq[k-i] = 0;
            }
        }
        
        return ans;
    }
};