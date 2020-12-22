// Created by wuyou on 2020/12/22.

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/*
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
 * PS：每次只能向下或者向右移动一步。
 */

/*
 * 左上到右下的最小路径
 */

// 递归
class MinimumPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        assert(m > 0);
        int n = grid[0].size();

        return dfs(grid, m - 1, n - 1);
    }

    // 从 (0,0) 到 (i,j) 的最短路径和
    int dfs(vector<vector<int>>& grid, int i, int j) {

        // 左上角 (0,0) 点没有左侧和上侧元素
        if (i == 0 && j == 0)
            return grid[0][0];

        // 最上层元素 (1,0) ~ (i-1,0) 点没有左侧和上侧元素
        if (i == 0)
            return dfs(grid, i, j - 1) + grid[i][j];

        // 最左侧元素 (0,1) ~ (0,i-1) 点没有左侧和上侧元素
        if (j == 0)
            return dfs(grid, i - 1, j) + grid[i][j];

        // 其余元素
        return min(dfs(grid, i - 1, j), dfs(grid, i, j - 1)) + grid[i][j];
    }

    void test_case() {
        vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
        cout << minPathSum(grid) << endl;
    }
};

// 记忆化搜索
class MinimumPathSum_Memo {
public:
    vector<vector<int>> memo;
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        assert(m > 0);
        int n = grid[0].size();

        memo = vector<vector<int>>(m, vector<int>(n, 0));

        return dfs(grid, m - 1, n - 1);
    }

    // 从 (0,0) 到 (i,j) 的最短路径和
    int dfs(vector<vector<int>>& grid, int i, int j) {

        if (i == 0 && j == 0) return memo[0][0] = grid[0][0];

        if (i == 0) return memo[i][j] = dfs(grid, i, j - 1) + grid[i][j];

        if (j == 0) return memo[i][j] = dfs(grid, i - 1, j) + grid[i][j];

        if (memo[i][j] != 0)
            return memo[i][j];

        return memo[i][j] = min(dfs(grid, i - 1, j), dfs(grid, i, j - 1)) + grid[i][j];
    }


    void test_case() {
        vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
        cout << minPathSum(grid) << endl;
    }
};

// 动态规划
class MinimumPathSum_DP {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        assert(m > 0);
        int n = grid[0].size();

        // dp[i][j] 表示从 (0,0) 到 (i,j) 的最短路径和
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 左上角
        dp[0][0] = grid[0][0];

        // 上边缘与左边缘
        for (int j = 0; j < n - 1; j ++)
            dp[0][j + 1] = dp[0][j] + grid[0][j + 1];
        for (int i = 0; i < m - 1; i ++)
            dp[i + 1][0] = dp[i][0] + grid[i + 1][0];

        // 其余位置
        for (int i = 0; i < m - 1; i ++)
            for (int j = 0; j < n - 1; j ++)
                dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i + 1][j + 1];

        // 右下角即为所求
        return dp[m - 1][n - 1];
    }

    void test_case() {
        vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
        cout << minPathSum(grid) << endl;
    }
};







