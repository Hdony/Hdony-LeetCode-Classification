// Created by wuyou on 2020/12/20.

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

/*
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 *
 */

// 递归
class MinimumPathTotal {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return dfs(triangle, 0, 0); // 计算三角形 triangle[0][0] 的最小路径和
    }

    // 以 triangle[i][j] 为三角形顶点的最小路径和
    int dfs(vector<vector<int>>& triangle, int i, int j) {

        // 最后一层的下一层（即索引为 n 的层）没有元素，即没有三角形，返回 0
        if (i == triangle.size())
            return 0;

        // triangle[i][j] 的值是由正下方和右下方，两个三角形（最小路径和）中的较小者，加上自身的值得到的
        return min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }

    void test_case() {
        vector<vector<int>> triangle = {{1},
                                        {1,2},
                                        {3,2,3},
                                        {1,3,2,3},
                                        {4,2,3,2,1}};
        cout << minimumTotal(triangle) << endl;
    }
};

// 记忆化搜索
class MinimumPathTotal_Memo {
public:
    // memo[i][j] 记录以 triangle[i][j] 为顶点的三角形的最小路径和
    vector<vector<int>> memo;
    int minimumTotal(vector<vector<int>>& triangle) {

        // 三角形每一层的深度和宽度相同
        int depth = triangle.size();
        int width = depth;

        // 由于 triangle[i][j] 均为正整数，设置初值为 0
        memo = vector<vector<int>>(depth, vector<int>(width, 0));
        return dfs(triangle, 0, 0);
    }

    int dfs(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size())
            return 0;

        // 当不同三角形存在重叠区域时，该区域不会重复计算，而是直接读取 memo
        if (memo[i][j] != 0)
            return memo[i][j];

        return memo[i][j] = min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }

    void test_case() {
        vector<vector<int>> triangle = {{1},
                                        {1,2},
                                        {3,2,3},
                                        {1,3,2,3},
                                        {4,2,3,2,1}};
        cout << minimumTotal(triangle) << endl;
    }
};

// 动态规划
class MinimumPathTotal_DP {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // dp[i][j] 表示从点 (i, j) 到底边的最小路径和
        // dp[n][j] 将最底层（索引为 n）初始化为 0
        vector<vector<int>> dp(n + 1, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i --) // 从底向上
            for (int j = 0; j <= i; j ++) // 从左向右
                // 最短路径 dp[i][j] 是由最短路径 dp[i+1][j] 和最短路径 dp[i+1][j+1] 中较小者加上
                // 当前元素 triangle[i][j] 得到的
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            
        return dp[0][0];
    }

    void test_case() {
        vector<vector<int>> triangle = {{1},
                                        {1,2},
                                        {3,2,3},
                                        {1,3,2,3},
                                        {4,2,3,2,1}};
        cout << minimumTotal(triangle) << endl;
    }
};
