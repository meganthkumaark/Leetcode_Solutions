

class Solution {
public:
    int maxScore(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> max_future_value(m, std::vector<int>(n, -1e9));
        max_future_value[m-1][n-1] = grid[m-1][n-1];

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i < m-1) {
                    max_future_value[i][j] = std::max(max_future_value[i][j], max_future_value[i+1][j]);
                }
                if (j < n-1) {
                    max_future_value[i][j] = std::max(max_future_value[i][j], max_future_value[i][j+1]);
                }
                max_future_value[i][j] = std::max(max_future_value[i][j], grid[i][j]);
            }
        }

        int max_score = -1e9;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i < m-1) {
                    max_score = std::max(max_score, max_future_value[i+1][j] - grid[i][j]);
                }
                if (j < n-1) {
                    max_score = std::max(max_score, max_future_value[i][j+1] - grid[i][j]);
                }
            }
        }

        return max_score;
    }
};