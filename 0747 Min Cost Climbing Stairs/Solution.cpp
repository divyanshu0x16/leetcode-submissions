class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int stepOne = 0;
        int stepTwo = 0;

        for (int i = 2; i < cost.size()+1; i++)
        {
            int temp = stepOne;
            stepOne = min(stepOne + cost[i-1], stepTwo + cost[i-2]);
            stepTwo = temp;
        }
        
        return stepOne;
    }
};