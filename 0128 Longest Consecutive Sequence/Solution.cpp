class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int, greater<int> > numSet;
        for (auto &&i : nums)
            numSet.insert(i);

        int longestStreak = 0;

        for (auto i : numSet)
        {
            if( numSet.find(i-1) == numSet.end()){
                int currentNum = i;
                int curretnStreak = 1;

                while (numSet.find(currentNum+1) != numSet.end())
                {
                    currentNum += 1;
                    curretnStreak += 1;
                }

                longestStreak = max(longestStreak, curretnStreak); 
            }
        }
        return longestStreak; 
    }
};


 