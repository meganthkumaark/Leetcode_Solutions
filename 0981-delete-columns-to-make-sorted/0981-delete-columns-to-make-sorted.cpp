#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int num_columns = A[0].size();
        int num_deleted = 0;
        
        for (int col = 0; col < num_columns; ++col) {
            for (int row = 1; row < A.size(); ++row) {
                if (A[row][col] < A[row - 1][col]) {
                    num_deleted++;
                    break;
                }
            }
        }
        
        return num_deleted;
    }
};
