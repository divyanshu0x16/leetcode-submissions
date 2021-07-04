class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> aVowelPermutationCount(n);
        vector<long> eVowelPermutationCount(n);
        vector<long> iVowelPermutationCount(n);
        vector<long> oVowelPermutationCount(n);
        vector<long> uVowelPermutationCount(n);

        aVowelPermutationCount[0] = 1;
        eVowelPermutationCount[0] = 1;
        iVowelPermutationCount[0] = 1;
        oVowelPermutationCount[0] = 1;
        uVowelPermutationCount[0] = 1;

        int MOD = 1e9+7;
        
        for (int i = 1; i < n; i++)
        {
            aVowelPermutationCount[i] = (eVowelPermutationCount[i-1] + iVowelPermutationCount[i-1] + uVowelPermutationCount[i-1])%MOD;
            eVowelPermutationCount[i] = (aVowelPermutationCount[i-1] + iVowelPermutationCount[i-1])%MOD;
            iVowelPermutationCount[i] = (eVowelPermutationCount[i-1] + oVowelPermutationCount[i-1])%MOD;
            oVowelPermutationCount[i] = (iVowelPermutationCount[i-1])%MOD;
            uVowelPermutationCount[i] = (iVowelPermutationCount[i-1] + oVowelPermutationCount[i-1])%MOD;
        }

        long result = (aVowelPermutationCount[n-1]+eVowelPermutationCount[n-1]+iVowelPermutationCount[n-1]+oVowelPermutationCount[n-1]+uVowelPermutationCount[n-1])%MOD;
        
        return (int)result;
    }
};