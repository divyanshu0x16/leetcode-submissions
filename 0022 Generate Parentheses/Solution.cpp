class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0){
            ans.push_back("");
        } else {
            for (int i = 0; i < n; i++)
                for (auto &&left : generateParenthesis(i))
                    for (auto &&right : generateParenthesis(n-1-i))
                        ans.push_back("(" + left + ")" + right);
        }
        return ans;
    }
};