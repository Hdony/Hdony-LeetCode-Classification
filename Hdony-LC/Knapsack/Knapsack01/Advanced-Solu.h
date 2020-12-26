// Created by wuyou on 2020/12/24.

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 0-1 背包问题变种问题 (1)
 * 完全背包问题：每个物品可以无限使用
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

        int res = dfs(w, v, C, index - 1);

        for (int k = 0; k * w[index] <= C; k++)
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
            res = max(res, v[index] * k + dfs(w, v, C - w[index] * k, index - 1));

        return memo[index][C] = res;
    }

    void test_case() {
        vector<int> w = {3,7,4,2,1,5};
        vector<int> v = {4,6,8,2,1,2};
        int C = 15;
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
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }

        return dp[n - 1][C];
    }

    void test_case() {
        vector<int> w = {3,7,4,2,1,5};
        vector<int> v = {4,6,8,2,1,2};
        int C = 15;
        cout << bestValue(w, v, C) << endl;
    }
};


/*
 * 0-1 背包问题变种问题 (2)
 * 多重背包问题：每个物品不止一个，有 M[i] 个
 */

// 递归
class KnapsackMultiple {
public:

    int bestValue(vector<int> w, vector<int> v, vector<int> M, int C) {
        int n = w.size();
        return dfs(w, v, M, C, n - 1);
    }

    // index: 当前物品的序号，考虑用 [0...index] 的物品，填充容积为 C 的背包的最大价值
    int dfs(vector<int> w, vector<int> v, vector<int> M, int C, int index) {

        // 当没有物品或者背包没有空间时，返回的价值为 0
        if (index < 0 || C <= 0)
            return 0;

        int res = dfs(w, v, M, C, index - 1);

        for (int k = 0; k <= M[index] && k * w[index] <= C; k ++)
            res = max(res, dfs(w, v, M, C - w[index] * k, index - 1) + v[index] * k);

        return res;
    }

    void test_case() {
        vector<int> w = {3,7,4,2,1,5};
        vector<int> M = {1,3,5,4,2,6};
        vector<int> v = {4,6,8,2,1,2};
        int C = 15;
        cout << bestValue(w, v, M, C) << endl;
    }
};

// 记忆化搜索
class KnapsackMultiple_Memo {
public:
    vector<vector<int>> memo;
    int bestValue(vector<int> w, vector<int> v, vector<int> M, int C) {
        int n = w.size();
        memo = vector<vector<int>>(n, vector<int>(C + 1, -1));
        return dfs(w, v, M, C, n - 1);
    }

    int dfs(vector<int> w, vector<int> v, vector<int> M, int C, int index) {
        if (index < 0 || C <= 0)
            return 0;

        if (memo[index][C] != -1)
            return memo[index][C];

        int res = dfs(w, v, M, C, index - 1);

        for (int k = 0; k <= M[index] && k * w[index] <= C; k ++)
            res = max(res, v[index] * k + dfs(w, v, M, C - w[index] * k, index - 1));

        return memo[index][C] = res;
    }

    void test_case() {
        vector<int> w = {3,7,4,2,1,5};
        vector<int> M = {1,3,5,4,2,6};
        vector<int> v = {4,6,8,2,1,2};
        int C = 15;
        cout << bestValue(w, v, M, C) << endl;
    }
};

// 动态规划
class KnapsackMultiple_DP {
public:
    int bestValue(vector<int> w, vector<int> v, vector<int> M, int C) {

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
                for (int k = 0; k <= M[i] && k * w[i] <= j; k ++)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }

        return dp[n - 1][C];
    }

    void test_case() {
        vector<int> w = {3,7,4,2,1,5};
        vector<int> M = {1,3,5,4,2,6};
        vector<int> v = {4,6,8,2,1,2};
        int C = 15;
        cout << bestValue(w, v, M, C) << endl;
    }
};


/*
 * 0-1 背包问题变种问题 (3)
 * 多维费用问题：考虑物品的体积和重量两个维度
 */

// 递归
class KnapsackMultiFee {
public:

    int bestValue(vector<int> w1, vector<int> w2, vector<int> v, int C1, int C2) {
        int n = w1.size();
        return dfs(w1, w2, v, C1, C2, n - 1);
    }

    // index: 当前物品的序号，考虑用 [0...index] 的物品，填充载重为 C1, 容积为 C2 的背包的最大价值
    // w1[index], w2[index] 分别为当前物品的两个维度的消耗（如重量和体积）
    int dfs(vector<int> w1, vector<int> w2, vector<int> v, int C1, int C2, int index) {

        if (index < 0 || C1 <= 0 || C2 <= 0)
            return 0;

        int res = dfs(w1, w2, v, C1, C2, index - 1);

        if (C1 >= w1[index] && C2 >= w2[index])
            res = max(res, dfs(w1, w2, v, C1 - w1[index], C2 - w2[index], index - 1) + v[index]);

        return res;
    }

    void test_case() {
        vector<int> w1 = {3,7,4,2,1,5};
        vector<int> w2 = {1,3,5,4,2,6};
        vector<int> v = {4,6,8,2,1,2};
        int C1 = 11, C2 = 10;
        cout << bestValue(w1, w2, v, C1, C2) << endl;
    }
};

// 记忆化搜索
class KnapsackMultiFee_Memo {
public:
    vector<vector<vector<int>>> memo;
    int bestValue(vector<int> w1, vector<int> w2, vector<int> v, int C1, int C2) {
        int n = w1.size();
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(C1 + 1, vector<int>(C2 + 1, -1)));
        return dfs(w1, w2, v, C1, C2, n - 1);
    }

    int dfs(vector<int> w1, vector<int> w2, vector<int> v, int C1, int C2, int index) {
        if (index < 0 || C1 <= 0 || C2 <= 0)
            return 0;

        if (memo[index][C1][C2] != -1)
            return memo[index][C1][C2];

        int res = dfs(w1, w2, v, C1, C2, index - 1);

        if (C1 >= w1[index] && C2 >= w2[index])
            res = max(res, dfs(w1, w2, v, C1 - w1[index], C2 - w2[index], index - 1) + v[index]);

        return memo[index][C1][C2] = res;
    }

    void test_case() {
        vector<int> w1 = {3,7,4,2,1,5};
        vector<int> w2 = {1,3,5,4,2,6};
        vector<int> v = {4,6,8,2,1,2};
        int C1 = 11, C2 = 10;
        cout << bestValue(w1, w2, v, C1, C2) << endl;
    }
};

// 动态规划
class KnapsackMultiFee_DP {
public:
    int bestValue(vector<int> w1, vector<int> w2, vector<int> v, int C1, int C2) {

        assert(w1.size() == v.size() && w2.size() == v.size());
        int n = w1.size();

        if (n == 0 || C1 == 0 || C2 == 0)
            return 0;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(C1 + 1, vector<int>(C2 + 1,-1)));

        // i,j,k 分别为 物品 id, 重量, 体积
        for (int j = 0; j <= C1; j ++)
            for (int k = 0; k <= C2; k ++)
                dp[0][j][k] = (j >= w1[0] && k >= w2[0] ? v[0] : 0);

        for (int i = 1; i < n; i ++)
            for (int j = 0; j <= C1; j ++)
                for (int k = 0; k <= C2; k ++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= w1[i] && k >= w2[i])
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - w1[i]][k - w2[i]] + v[i]);
                }

        return dp[n - 1][C1][C2];
    }

    void test_case() {
        vector<int> w1 = {3,7,4,2,1,5};
        vector<int> w2 = {1,3,5,4,2,6};
        vector<int> v = {4,6,8,2,1,2};
        int C1 = 11, C2 = 10;
        cout << bestValue(w1, w2, v, C1, C2) << endl;
    }
};


/*
 * 0-1 背包问题变种问题 (4)
 * 物品之间加入更多约束（物品之间可以互相排斥，也可以互相依赖）
 */





