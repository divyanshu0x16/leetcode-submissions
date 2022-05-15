class Solution
{

    bool areAnagram(string str1, string str2)
    {
        int n1 = str1.length();
        int n2 = str2.length();

        if (n1 != n2)
            return false;

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        for (int i = 0; i < n1; i++)
            if (str1[i] != str2[i])
                return false;

        return true;
    }

public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        stack<string> final;
        final.push(words[0]);

        for (int i = 1; i < words.size(); i++)
        {
            if (areAnagram(final.top(), words[i]))
                continue;
            else
                final.push(words[i]);
        }

        vector<string> ans;

        while (!final.empty())
        {
            ans.push_back(final.top());
            final.pop();
        }

        vector<string> finalAns;

        for (int i = ans.size()-1; i >= 0; i--)
            finalAns.push_back(ans[i]);
        
        return finalAns;
    }
};