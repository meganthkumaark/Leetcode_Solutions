#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> scores(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            scores[i] = {nums[i], i};
        }
        
        sort(scores.rbegin(), scores.rend());
        
        vector<string> result(nums.size(), "");
        
        for (int i = 0; i < scores.size(); ++i) {
            if (i == 0) {
                result[scores[i].second] = "Gold Medal";
            } else if (i == 1) {
                result[scores[i].second] = "Silver Medal";
            } else if (i == 2) {
                result[scores[i].second] = "Bronze Medal";
            } else {
                result[scores[i].second] = to_string(i + 1);
            }
        }
        
        return result;
    }
};
