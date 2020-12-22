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
 *
 */

class IntegerBreak {
public:
    int integerBreak(int n) {
        return dfs(n);
    }

    // 拆分 n 后得到的最大乘积
    int dfs(int n) {
        if (n == 1)
            return 1;
        int res = -1;
        for (int i = 1; i <= n - 1; i ++)
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










