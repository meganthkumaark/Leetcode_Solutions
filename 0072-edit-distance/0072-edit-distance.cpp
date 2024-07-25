class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        if (m == 0 || n == 0)
            return max(m, n);

        if (m < n)
            return minDistance(word2, word1);

        vector<int> dp(n + 1);

        for (int j = 0; j <= n; ++j)
            dp[j] = j;

        int prev, temp;
        for (int i = 1; i <= m; ++i) {
            prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                temp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = prev;
                else
                    dp[j] = min({prev, dp[j], dp[j - 1]}) + 1;
                prev = temp;
            }
        }

        return dp[n];
    }
};
