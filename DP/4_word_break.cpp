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
    bool exists(string s, unordered_set<string> strSet) {
        return strSet.find(s) != strSet.end();
    }
    
    bool check(string s, unordered_set<string> strSet, int pos, vector<int>& dp) {
        if (pos == s.length()) {
            return true;
        }
        
        if (dp[pos] != INT_MAX) {
            return dp[pos] == 1;
        }
        
        string wordTillNow = "";
        for (int i = pos; i < s.length(); i++) {
            wordTillNow += string(1, s[i]);
            if (exists(wordTillNow, strSet) and check(s, strSet, i+1, dp)) {
                dp[pos] = 1;
                return true;
            }
        }
        dp[pos] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> strSet;
        for (auto s: wordDict) {
            strSet.insert(s);
        }
        
        vector<int>dp(s.length(), INT_MAX);
        return check(s, strSet, 0, dp);
        
    }
};
