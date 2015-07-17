#include <string>
using namespace std;
class Solution {
    public:
        string longestPalindrome(string s) {
            const int n = s.size();
            bool dp[n][n];
            fill_n(&dp[0][0], n*n, false);
            for (int i = 0; i < n; i++)
                dp[i][i] = true;
            int max = 1;
            int start = 0;
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (s[i] == s[j] && (j - i < 2 || dp[i + 1,j - 1]))
                        dp[i][j] = true;
                    if (dp[i][j] && max < j - i + 1) {
                        max = j - 1 + 1;
                        start = i;
                    }
                }
            }
            return s.substr(start, max);
        }

};

