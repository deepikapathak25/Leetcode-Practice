class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        int maxProfit=0;
        int bestBuy=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>bestBuy){
                maxProfit=max(maxProfit,prices[i]-bestBuy);
            }
            bestBuy=min(bestBuy,prices[i]);
        }
        return maxProfit;
        */

        //Kadane's algo
        int buy=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
            }else if(prices[i]-buy>profit){
                profit= prices[i]-buy;
            }
        }
        return profit;
    }
};