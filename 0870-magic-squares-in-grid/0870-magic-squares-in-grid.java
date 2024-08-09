class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        if (rows < 3 || cols < 3) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isValidMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
    
    private boolean isValidMagicSquare(int[][] grid, int startRow, int startCol) {
        boolean[] numPresence = new boolean[10];
        int targetSum = 0;
        
        // Check for distinct numbers and calculate sums
        for (int i = 0; i < 3; i++) {
            int rowSum = 0;
            int colSum = 0;
            for (int j = 0; j < 3; j++) {
                int num = grid[startRow + i][startCol + j];
                if (num < 1 || num > 9 || numPresence[num]) {
                    return false;
                }
                numPresence[num] = true;
                rowSum += num;
                colSum += grid[startRow + j][startCol + i];
            }
            if (i == 0) {
                targetSum = rowSum;
            } else if (rowSum != targetSum || colSum != targetSum) {
                return false;
            }
        }
        
        // Check diagonals
        int mainDiagonalSum = grid[startRow][startCol] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol + 2];
        int antiDiagonalSum = grid[startRow][startCol + 2] + grid[startRow + 1][startCol + 1] + grid[startRow + 2][startCol];
        
        return mainDiagonalSum == targetSum && antiDiagonalSum == targetSum;
    }
}