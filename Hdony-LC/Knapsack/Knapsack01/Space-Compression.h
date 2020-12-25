// Created by wuyou on 2020/12/24.

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 0-1 背包问题
 * 对简单背包问题的空间复杂度进行压缩
 * 以动态规划为例
 */

class Knapsack01_SC1 {
public:
    int bestValue(vector<int> w, vector<int> v, int C) {

        assert(w.size() == v.size());
        int n = w.size();

        if (n == 0 || C == 0)
            return 0;

        vector<vector<int>> dp(2, vector<int>(C + 1, -1));

        for (int j = 0; j <= C; j ++)
            dp[0][j] = (j >= w[0] ? v[0] : 0);

        // 仅保留两行，交替赋值
        for (int i = 1; i < n; i ++)
            for (int j = 0; j <= C; j ++) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (j >= w[i])
                    dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - w[i]] + v[i]);
            }

        return dp[(n - 1) % 2][C];
    }

    void test_case() {
        vector<int> w = {3,1,4,1,2,3,5};
        vector<int> v = {4,6,8,2,1,2,7};
        int C = 10;
        cout << bestValue(w, v, C) << endl;
    }
};

class Knapsack01_SC2 {
public:
    int bestValue(vector<int> w, vector<int> v, int C) {

        assert(w.size() == v.size());
        int n = w.size();

        if (n == 0 || C == 0)
            return 0;

        // 仅保留 1 行，从右向左移动
        vector<int> dp(C + 1, -1);

        for (int j = 0; j <= C; j ++)
            dp[j] = (j > w[0] ? v[0] : 0);

        for (int i = 1; i < n; i ++)
            for (int j = C; j >= w[i]; j --)
                dp[j] = max(dp[j], v[i] + dp[j - w[i]]);

        return dp[C];
    }

    void test_case() {
        vector<int> w = {3,1,4,1,2,3,5};
        vector<int> v = {4,6,8,2,1,2,7};
        int C = 10;
        cout << bestValue(w, v, C) << endl;
    }
};

