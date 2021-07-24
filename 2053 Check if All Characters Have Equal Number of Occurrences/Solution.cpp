class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> freq;

        for (auto &&i : s)
            freq[i]++;

        vector<int> frequencies;
        for (auto &&i : freq)
            frequencies.push_back(i.second);
        
        for (int i = 1; i < frequencies.size(); i++)
            if(frequencies[i] != frequencies[i-1]) return false;
        
        return true;
    }
};