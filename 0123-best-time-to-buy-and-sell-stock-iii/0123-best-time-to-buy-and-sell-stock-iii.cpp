#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int firstBuy = INT_MIN;
        int firstSell = 0;
        int secondBuy = INT_MIN;
        int secondSell = 0;

        for (int price : prices) {
            firstBuy   = std::max(firstBuy, -price);
            firstSell  = std::max(firstSell, firstBuy + price);
            secondBuy  = std::max(secondBuy, firstSell - price);
            secondSell = std::max(secondSell, secondBuy + price);
        }

        return secondSell;
    }
};