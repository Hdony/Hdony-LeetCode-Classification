// Created by wuyou on 2020/12/29.

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n
 * 你需要让组成和的完全平方数的个数最少。
 */

/*
 * 归纳为完全背包问题：w=[1,4,9...floor(sqrt(n))], C=n
 */

class NumberSquares {
public:
    int numSquares(int n) {

        // 构造一个 w 数组
        vector<int> w;
        for (int i = 1; i <= int(sqrt(n)); i ++)
            w.push_back(i * i);

        return dfs(n, w);
    }

    // 用重量为 [1,4,9...floor(sqrt(n))] 的物品恰好填充容积为 C 的背包
    int dfs(int C, int sqr) {

        if (sqr < 1 || C <= 0)
            return 0;

        int res = INT_MAX;

        for (int i = 1; i < )

        return res;
    }

    void test_case() {
        int n = 55;
        cout << numSquares(n) << endl;
    };
};
//int numSquares(int n) {
//    int* dp = new int[n + 1];
//    dp[0] = 0;
//    for (int i = 1; i <= n; ++i)
//        dp[i] = INT_MAX;
//
//    for (int i = 1; i * i <= n; i ++)
//        for (int j = i * i; j <= n; j ++) {
//            dp[j] = min(dp[j], dp[j - i * i] + 1);
//
//        }
//
//    for (int i = 1, sqr = i * i; sqr <= n; ++i, sqr = i * i)
//        for (int j = sqr; j <= n; ++j)
//            dp[j] = min(dp[j], dp[j - sqr] + 1);
//    return dp[n];
//}
#include <unordered_set>
int numSquares(int n) {
    unordered_set<int> squares;
    for (int i = 1, e = sqrt(n); i <= e; i++)
        squares.insert(i * i);

    return dfs(n, squares);
}

int dfs(int n, const unordered_set<int>& squares) {
    if (squares.count(n))
        return 1;

    int minNum = INT_MAX;
    for (const auto& square : squares)
        if (n > square)
            minNum = min(minNum, dfs(n - square, squares) + 1);
    return minNum;
}
