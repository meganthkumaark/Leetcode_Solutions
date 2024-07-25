class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return dfs(s, dict, memo);
    }

private:
    vector<string> dfs(const string& s, const unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        
        vector<string> result;
        
        if (dict.find(s) != dict.end()) {
            result.push_back(s);
        }
        
        for (int i = 1; i < s.size(); ++i) {
            string right = s.substr(i);
            if (dict.find(right) != dict.end()) {
                vector<string> leftResults = dfs(s.substr(0, i), dict, memo);
                for (const string& left : leftResults) {
                    result.push_back(left + " " + right);
                }
            }
        }
        
        memo[s] = result;
        return result;
    }
};