class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell = 0;
        for (const int price : prices) {
            buy = std::min(buy, price);
            sell = std::max(sell, price - buy);
        }
        return sell;
    }
};
