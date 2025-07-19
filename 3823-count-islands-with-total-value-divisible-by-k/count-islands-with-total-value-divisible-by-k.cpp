class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        long long  sum = temp;
        sum += dfs(grid, i + 1, j, m, n);
        sum += dfs(grid, i - 1, j, m, n);
        sum += dfs(grid, i, j + 1, m, n);
        sum += dfs(grid, i, j - 1, m, n);
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    long long temp = dfs(grid, i, j, m, n);
                    if (temp % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
