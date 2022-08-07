class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
        int buy = 0;

        int minPrice = 10001;
        int maxProfit =  0;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
};