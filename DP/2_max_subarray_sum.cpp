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
    int maxSubArray(vector<int>& nums) {
        int maxtillnow = nums[0];
        int maxendinghere = 0;
        for (int i = 0; i < nums.size(); i++){
            maxendinghere = maxendinghere + nums[i];
            if (maxtillnow < maxendinghere){
                maxtillnow = maxendinghere;
            }
            
            if (maxendinghere < 0) maxendinghere = 0;
        }
        return maxtillnow;
    }
};
