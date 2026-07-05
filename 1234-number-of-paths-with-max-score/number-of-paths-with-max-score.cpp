class Solution {
public:
    int func2(vector<string>& board, int m, int n, int row, int col,
              vector<vector<int>>& dp, vector<vector<int>>& countDp) {
        if (row == 0 && col == 0)
            return 1;
        if (row < 0 || col < 0 || board[row][col] == 'X')
            return 0;

        if (countDp[row][col] != -1)
            return countDp[row][col];

        int val = (board[row][col] == 'S') ? 0 : board[row][col] - '0';
        long long ways = 0;
        int MOD = 1e9 + 7;

        if (col - 1 >= 0 && dp[row][col - 1] != -1 &&
            dp[row][col] == val + dp[row][col - 1]) {
            ways = (ways + func2(board, m, n, row, col - 1, dp, countDp)) % MOD;
        }
        if (row - 1 >= 0 && col - 1 >= 0 && dp[row - 1][col - 1] != -1 &&
            dp[row][col] == val + dp[row - 1][col - 1]) {
            ways = (ways + func2(board, m, n, row - 1, col - 1, dp, countDp)) %
                   MOD;
        }
        if (row - 1 >= 0 && dp[row - 1][col] != -1 &&
            dp[row][col] == val + dp[row - 1][col]) {
            ways = (ways + func2(board, m, n, row - 1, col, dp, countDp)) % MOD;
        }
        return countDp[row][col] = ways;
    }
    int func(vector<string>& board, int m, int n, int row, int col,
             vector<vector<int>>& dp) {
        if (row >= m || col >= n || row < 0 || col < 0)
            return -1e5;
        if (board[row][col] == 'X')
            return -1e5;
        if (board[row][col] == 'E')
            dp[row][col] = 0;
        int val = board[row][col] != 'S' ? board[row][col] - '0' : 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int left = val + func(board, m, n, row, col - 1, dp);
        int diag = val + func(board, m, n, row - 1, col - 1, dp);
        int up = val + func(board, m, n, row - 1, col, dp);
        return dp[row][col] = max({left, diag, up});
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<int>> countDp(m, vector<int>(n, -1));

        int maxi = func(board, m, n, m - 1, n - 1, dp);

        // If maxi is negative, it means 'E' is unreachable from 'S
        if (maxi < 0) {
            return {0, 0};
        }

        int maxNum = func2(board, m, n, m - 1, n - 1, dp, countDp);

        return {maxi, maxNum};
    }
};