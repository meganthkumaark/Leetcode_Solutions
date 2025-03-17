class Solution {
    public int cs(int n, int[] dp){
        if(n == 0) return 1;
        if(n == 1) return 1;
        if( dp[n] != 0){
            return dp[n];
        }
        return dp[n] = cs(n - 1, dp) + cs(n - 2, dp);
    }
    public int climbStairs(int n) {
        int[] dp = new int[n + 1];
        return cs(n, dp);
    }
}