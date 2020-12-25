// Created by wuyou on 2020/12/24.

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 0-1 背包问题变种问题 (1)
 * 完全背包问题：每个物品可以无限使用
 * 以动态规划为例
 */

// 递归
class KnapsackTotal {
public:

    int bestValue(vector<int> w, vector<int> v, int C) {
        int n = w.size();
        return dfs(w, v, C, n - 1);
    }

    // index: 当前物品的序号，考虑用 [0...index] 的物品，填充容积为 C 的背包的最大价值
    int dfs(vector<int> w, vector<int> v, int C, int index) {

        // 当没有物品或者背包没有空间时，返回的价值为 0
        if (index < 0 || C <= 0)
            return 0;

        // 先用 [0...index] 的物品填充 C，若背包总空间可容纳当前物品，
        // 考虑用 [0...index-1] 的物品填充 C-w[index]，得到的价值与前一种价值取较大者
        int res = dfs(w, v, C, index - 1);

        for (int k = 0; k * w[index] <= C; k++)
            if (C >= w[index])
                res = max(res, v[index] * k + dfs(w, v, C - w[index] * k, index - 1));

        return res;
    }

    void test_case() {
        vector<int> w = {3,7,4,2,1,5};
        vector<int> v = {4,6,8,2,1,2};
        int C = 15;
        cout << bestValue(w, v, C) << endl;
    }
};

// 记忆化搜索
class KnapsackTotal_Memo {
public:
    vector<vector<int>> memo;
    int bestValue(vector<int> w, vector<int> v, int C) {
        int n = w.size();
        memo = vector<vector<int>>(n, vector<int>(C + 1, -1));
        return dfs(w, v, C, n - 1);
    }

    int dfs(vector<int> w, vector<int> v, int C, int index) {
        if (index < 0 || C <= 0)
            return 0;

        if (memo[index][C] != -1)
            return memo[index][C];

        int res = dfs(w, v, C, index - 1);

        for (int k = 0; k * w[index] <= C; k ++)
            if (C >= w[index])
                res = max(res, v[index] * k + dfs(w, v, C - w[index] * k, index - 1));

        return memo[index][C] = res;
    }

    void test_case() {
        vector<int> w = {3,1,4,1,2,3,5};
        vector<int> v = {4,6,8,2,1,2,7};
        int C = 10;
        cout << bestValue(w, v, C) << endl;
    }
};

// 动态规划
class KnapsackTotal_DP {
public:
    int bestValue(vector<int> w, vector<int> v, int C) {

        assert(w.size() == v.size());
        int n = w.size();

        if (n == 0 || C == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(C + 1, -1));

        // 填充第一行
        for (int j = 0; j <= C; j ++) // j: 一个容积为 j 的背包
            dp[0][j] = (j >= w[0] ? v[0] : 0);

        // 填充其余行
        for (int i = 1; i < n; i ++)
            for (int j = 0; j <= C; j ++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 0; k * w[i] <= j; k ++)
                    if (j >= w[i])
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }

        return dp[n - 1][C];
    }

    void test_case() {
        vector<int> w = {3,1,4,1,2,3,5};
        vector<int> v = {4,6,8,2,1,2,7};
        int C = 10;
        cout << bestValue(w, v, C) << endl;
    }
};





