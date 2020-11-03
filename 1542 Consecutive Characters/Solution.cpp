class Solution {
public:
    int maxPower(string s) {
        int power = 1;
        int ans = 1;
        for(int i = 1;i < s.length();i++){
            if(s[i] == s[i - 1])
                ans = max(ans,++power);
            else
                power = 1;
        }
        return ans;
    }
};