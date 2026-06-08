class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowestPrice = INT_MAX;

        /*


        store lowest price, as we iterate through the array, check if current price is less than lowest price
        if it is update lowest price
        
        at each price, do price - lowest price, if its greater than the current max profit, update max profit

        */

        for (int i = 0; i < prices.size(); i++)
        {
            lowestPrice = min(lowestPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-lowestPrice);
        }

        return maxProfit;
    }
};
