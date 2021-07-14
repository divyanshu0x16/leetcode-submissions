class Solution {
public:
    string customSortString(string order, string str) {
        map<char, int> freq;

        for (auto &&i : str)
            freq[i]++;

        string ans = "";
        for (auto &&i : order)
        {
            int currFreq = freq[i];
            for (int j = 0; j < currFreq; j++){
                ans += i;
                freq[i]--;
            }
        }
        
        for (auto &&i : freq)
            if( i.second != 0 )
                for (int j = 0; j < i.second; j++)
                    ans += i.first;

        return ans;
    }
};