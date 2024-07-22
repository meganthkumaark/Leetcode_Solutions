class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        if (n == 1) {
            std::vector<bool> result(queries.size(), true);
            return result;
        }
        
        std::vector<int> prefixSum(n, 0);
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + ((nums[i] % 2) == (nums[i - 1] % 2) ? 1 : 0);
        }
        
        std::vector<bool> result(queries.size());
        for (int q = 0; q < queries.size(); ++q) {
            int fromIndex = queries[q][0];
            int toIndex = queries[q][1];
            int sameParityCount = prefixSum[toIndex] - prefixSum[fromIndex];
            result[q] = (sameParityCount == 0);
        }
        
        return result;
    }
};