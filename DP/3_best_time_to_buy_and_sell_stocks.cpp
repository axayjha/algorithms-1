#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdint.h>
#include <regex>
#include <sstream>
#include <locale>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
