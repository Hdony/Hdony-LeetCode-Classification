// Created by wuyou on 2020/12/22.

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/*
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。
 * 返回可以获得的最大乘积
 * PS：假设 n 不小于 2 且不大于 58
 */

/*
 * 10 : max(-1,1*9,1*dfs(9)) max(-1,2*8,2*dfs(8)) max(-1,3*7,3*dfs(7)) max(-1,4*6,4*dfs(6)) ...
 *  9 : max(-1,1*8,1*dfs(8)) max(-1,2*7,2*dfs(7)) max(-1,3*6,3*dfs(6)) max(-1,4*5,4*dfs(5)) ...
 *  8 : max(-1,1*7,1*dfs(7)) max(-1,2*6,2*dfs(6)) max(-1,3*5,3*dfs(5)) max(-1,4*4,4*dfs(4)) ...
 *  7 : max(-1,1*6,1*dfs(6)) max(-1,2*5,2*dfs(5)) max(-1,3*4,3*dfs(4)) max(-1,4*3,4*dfs(3)) ...
 *  6 : max(-1,1*5,1*dfs(5)) max(-1,2*4,2*dfs(4)) max(-1,3*3,3*dfs(3)) max(-1,4*2,4*dfs(2)) ...
 *  5 : max(-1,1*4,1*dfs(4)) max(-1,2*3,2*dfs(3)) max(-1,3*2,3*dfs(2)) max(-1,4*1,4*dfs(1)) ...
 *  4 : max(-1,1*3,1*dfs(3)) max(-1,2*2,2*dfs(2)) max(-1,3*1,3*dfs(1))
 *  3 : max(-1,1*2,1*dfs(2)) max(-1,2*1,2*dfs(1))
 *  2 : max(-1,1*1,1*dfs(1))
 */

// 递归
class IntegerBreak {
public:
    int integerBreak(int n) {
        return dfs(n);
    }

    // 拆分 n 后得到的最大乘积
    int dfs(int n) {
        if (n == 1) return 1;
        int res = -1;
        for (int i = 1; i <= n - 1; i ++)
            // 拆分 n-i 时，每个元素需要非负，需要添加拆分成 n-i 和 0 的情况
            res = max3(res, i * (n - i), i * dfs(n - i));
        return res;
    }

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    void test_case() {
        int n = 10;
        cout << integerBreak(n) << endl;
    }
};

// 记忆化搜索
class IntegerBreak_Memo {
public:
    vector<int> memo; // 拆分 n 得到的最大乘积
    int integerBreak(int n) {
        assert(n >= 2);

        // 无法拆分 0，因此开 n+1 个空间，并舍弃 memo[0]
        memo = vector<int>(n + 1, -1);
        return dfs(n);
    }

    // 拆分 n 后得到的最大乘积
    int dfs(int n) {

        // 从拆分 1 开始
        if (n == 1) return 1;

        if (memo[n] != -1) return memo[n];

        int res = -1;
        for (int i = 1; i <= n - 1; i ++)
            res = max3(res, i * (n - i), i * dfs(n - i));
        return memo[n] = res;
    }

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    void test_case() {
        int n = 10;
        cout << integerBreak(n) << endl;
    }
};

// 动态规划
class IntegerBreak_DP {
public:
    int integerBreak(int n) {

        vector<int> dp(n + 1, -1);

        dp[1] = 1;
        for (int i = 2; i <= n; i ++)
            // 求 memo[i]
            for (int j = 1; j <= i - 1; j ++)
                // j + (i - j)
                dp[i] = max3(dp[i], j * (i - j), j * dp[i - j]);

        return dp[n];
    }

    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    void test_case() {
        int n = 10;
        cout << integerBreak(n) << endl;
    }
};







