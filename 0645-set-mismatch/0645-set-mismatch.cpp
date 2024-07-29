class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2, 0);
        
        for (int num : nums) {
            if (nums[abs(num) - 1] < 0) {
                result[0] = abs(num);  // Duplicate
            } else {
                nums[abs(num) - 1] *= -1;
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result[1] = i + 1;  // Missing
                break;
            }
        }
        
        return result;
    }
};