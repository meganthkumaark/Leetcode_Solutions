class Solution {
    unordered_map<int, vector<vector<int>>> dp;
    int solve(int k, int i, int jump, bool can) {
        if (i > k + 5)
            return 0;

        if(jump > 31)
            return 0;

        if(dp.count(i) && dp[i][jump][can] != -1)
            return dp[i][jump][can];

        int ans = (i == k);
        if (can)
            ans += solve(k, i - 1, jump, 0);
        if (i + (1 << jump) <= k + 1)
            ans += solve(k, i + (1 << jump), jump + 1, 1);

        dp[i].resize(32, vector<int>(2, -1));

        return dp[i][jump][can] = ans;
    }
public:
    int waysToReachStair(int k) {
        return solve(k, 1, 0, 1);
    } 
};