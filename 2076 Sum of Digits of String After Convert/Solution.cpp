class Solution {
public:
    int getLucky(string s, int k) {
        map<char, string> mapping;
        string alphabets = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 1; i <= 26; i++){
            mapping[alphabets[i-1]] = to_string(i);
        }

        string coversions = "";
        for (int i = 0; i < s.length(); i++)
            coversions += (mapping[s[i]]);

        while (k--)
        {
            int curr = 0;
            for (int i = 0; i < coversions.length(); i++)
                curr += stoi(coversions.substr(i, 1));

            coversions = to_string(curr);
        }
        
        return stoi(coversions);
    }
};