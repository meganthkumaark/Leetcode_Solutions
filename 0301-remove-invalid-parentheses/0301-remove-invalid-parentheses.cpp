class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                ans.push_back(current);
                found = true;
            }

            if (found) continue; 

            for (int i = 0; i < current.length(); ++i) {
                if (current[i] != '(' && current[i] != ')') continue;

                string next = current.substr(0, i) + current.substr(i + 1);

                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        return ans;
    }

private:
    bool isValid(const string& s) {
        int opened = 0;
        for (const char c : s) {
            if (c == '(')
                ++opened;
            else if (c == ')') {
                --opened;
                if (opened < 0) return false;
            }
        }
        return opened == 0;
    }
};
