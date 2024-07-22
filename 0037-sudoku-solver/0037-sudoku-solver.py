class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def isValid(board, row, col, c):
            for i in range(9):
                if board[row][i] == c:
                    return False
                if board[i][col] == c:
                    return False
                if board[row // 3 * 3 + i // 3][col // 3 * 3 + i % 3] == c:
                    return False
            return True

        def solve(board):
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for c in "123456789":
                            if isValid(board, i, j, c):
                                board[i][j] = c
                                if solve(board):
                                    return True
                                else:
                                    board[i][j] = '.'
                        return False
            return True

        solve(board)
