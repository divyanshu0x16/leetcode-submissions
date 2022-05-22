class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> difference(capacity.size(), 0);

        for (int i = 0; i < capacity.size(); i++)
        {
            difference[i] = capacity[i] - rocks[i];
        }
        //We have to make elements zero in difference
        sort(difference.begin(), difference.end());

        int sum = 0, count = 0;
        for (int i = 0; i < difference.size(); i++)
        {
            sum = sum + difference[i];

            if(sum > additionalRocks){
                break;
            }

            count++;
        }
        
        return count;
    }
};