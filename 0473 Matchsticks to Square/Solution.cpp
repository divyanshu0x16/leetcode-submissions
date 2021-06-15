class Solution {
    public:
    vector<int> matchsticks;
    int sums[4];
    int possibleSquareSide;

    bool dfs(int index, vector<int>& matchsticks){
        int n = matchsticks.size();
        if(index == n){
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
        }

        int element = matchsticks[index];

        for (int i = 0; i < 4; i++)
        {
            if( sums[i] + element <= possibleSquareSide){
                sums[i] += element;
                if( dfs(index+1, matchsticks) ){
                    return true;
                }
                sums[i] -= element;
            }
        }  
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        if( matchsticks.empty() ){
            return false;
        }
        
        int size = matchsticks.size();
        int permimeter = 0;
        for (int i = 0; i < size; i++)
        {
            permimeter += matchsticks[i];
        }

        possibleSquareSide = permimeter/4;

        if( possibleSquareSide*4 != permimeter){
            return false;
        }

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        return dfs(0, matchsticks);
    }
};
