class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = INT_MIN;
        for(int price : prices){
            minPrice = min(minPrice, price);
            profit = max(profit, price - minPrice);
        }
        return profit;
    }
};