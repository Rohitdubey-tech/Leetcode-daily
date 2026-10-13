class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        for(int price : prices){
            minPrice = min(minPrice, price);
            profit = max(profit, price - minPrice);
        }
        return profit;
    }
};