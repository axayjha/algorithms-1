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
    string longestPalindrome(string s) {
        int maxLen = 1, start = 0;
        string lps;
        
        int n = (int)s.length();
        if (n == 0) return string("");
        int low, high;
        for (int i = 1; i < n; i++) {
            low = i-1;
            high = i;
            while (low >= 0 and high < n and s[low] == s[high]) {
                if (maxLen < high - low + 1) {
                    start = low;
                    maxLen = high - low + 1;
                }
                low--;
                high++;
            }
            
            low = i-1;
            high = i+1;
            while (low >= 0 and high < n and s[low] == s[high]) {
                if (maxLen < high - low + 1) {
                    start = low;
                    maxLen = high - low + 1;
                }
                low--;
                high++;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

