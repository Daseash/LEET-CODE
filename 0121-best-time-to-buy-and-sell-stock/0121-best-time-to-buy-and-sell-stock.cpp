class Solution {
public:
    int maxProfit(vector<int>& prices) {
int profit = 0;
    int n = prices.size();
    if (n == 0) return 0;

    vector<int> maxVal(n);
    maxVal[n - 1] = prices[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        maxVal[i] = max(maxVal[i + 1], prices[i]);
    }

    for (int i = 0; i < n; i++) {
        int currProfit = maxVal[i] - prices[i];
        profit = max(currProfit, profit);
    }

    return profit;
}
};
