class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long current_sum = 1;
        int patches = 0;
        int i = 0;
        
        while (current_sum <= n) {
            if (i < nums.size() && nums[i] <= current_sum) {
                current_sum += nums[i];
                i++;
            } else {
                current_sum += current_sum;
                patches++;
            }
        }
        
        return patches;
    }
};
