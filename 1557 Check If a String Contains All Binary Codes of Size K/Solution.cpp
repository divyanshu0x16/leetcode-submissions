class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> us;
        
        for(int i = 0; i + k <= s.size(); i++ )
        {
            us.insert(s.substr(i, k));
        }
        return us.size() == 1 << k;
        
    }
};