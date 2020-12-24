// Created by wuyou on 2020/12/23.

#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

/*
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。
 * 你需要让组成和的完全平方数的个数最少。
 */

// 递归
//class PerfectSquares {
//public:
//    int numSquares(int n) {
//        return dfs(n);
//    }
//
//    // 将 n 拆分为完全平方数的最少个数
//    int dfs(int n) {
//        if (isSquare(n))
//            return 1;
//        int res = 0;
//        for (int i = 1; i <= n - 1; i ++) {
//            dfs(i) +
//        }
//    }
//
//    bool isSquare(int n) {
//        return pow(sqrt(n), 2) == n;
//    }
//};

