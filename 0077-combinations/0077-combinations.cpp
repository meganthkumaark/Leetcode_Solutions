class Solution {
public:
    void help(int idx, vector<int> ds, vector<vector<int>>& ans, int n, int k) {

        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        if (idx > n)
            return;
        for (int i = idx; i <= n; i++) {
            ds.push_back(i);
            help(i + 1, ds, ans, n, k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;
        help(1, ds, ans, n, k);
        return ans;
    }
};