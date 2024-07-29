class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> indices;

        for (int i = 0; i < n; ++i) {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                int prevIndex = indices.top();
                indices.pop();
                result[prevIndex] = i - prevIndex;
            }

            indices.push(i);
        }

        return result;
    }
};