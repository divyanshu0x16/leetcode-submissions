class Solution {
public:
    int percentageLetter(string s, char letter) {
        map<char, int> freq;

        for (auto &&i : s)
        {
            if( freq.find(i) == freq.end() ) freq[i] = 1;
            else freq[i] += 1;
        }
        
        if( freq.find(letter) == freq.end() ){
            return 0;    
        }else{
            double fraction = (freq[letter]*100)/s.length();
            return floor(fraction);
        }
        return 0;
    }
};