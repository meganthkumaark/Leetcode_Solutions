class Solution {
public:
    int n; 
    vector<vector<int>> ans;

    void solve(vector<int>& nums) {
         
         for(int i=0; i<(1<<n); i++) {
            vector<int> tmp;

            for(int j=0; j<n; j++) {
                if(i & (1<<j)) tmp.push_back(nums[j]);
            }

            ans.push_back(tmp);
         }

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        n = nums.size();

        solve(nums);

        return ans;
    }
};