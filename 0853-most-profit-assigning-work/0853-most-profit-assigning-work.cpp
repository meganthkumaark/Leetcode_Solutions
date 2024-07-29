class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> tasks;
        for (int i = 0; i < difficulty.size(); ++i) {
            tasks.emplace_back(difficulty[i], profit[i]);
        }
        sort(tasks.begin(), tasks.end());
        sort(worker.begin(), worker.end());

        int total_profit = 0;
        int max_profit = 0;
        int j = 0;

        for (int ability : worker) {
            while (j < tasks.size() && ability >= tasks[j].first) {
                max_profit = max(max_profit, tasks[j].second);
                ++j;
            }
            total_profit += max_profit;
        }

        return total_profit;
    }
};
