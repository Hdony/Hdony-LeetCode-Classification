// Created by George Wu on 2020/12/19.

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

/*
 * 剑指Offer-1：写一个函数，输入 n ，求斐波那契数列的第 n 项。斐波那契数列的定义如下：
 * F(0) = 0, F(1) = 1
 * F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
 * PS：0 <= n <= 100.
 */

// 递归
class Fibonacci {
public:
    // 递归方法
    int fib(int n) {
        return dfs(n);
    }

    // 斐波那契数列第 n 项的值
    int dfs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return dfs(n - 1) + dfs(n - 2);
    }

    void test_case() {
        int n = 40; // 大约 1 秒左右
        time_t start = clock();
        int res = fib(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

// 记忆化搜索
class Fibonacci_Memo {
public:
    vector<int> memo; // memo[i] 表示斐波那契数列第 i 项
    int fib(int n) {
        // [0...n] 一共 n+1 项
        memo = vector<int>(n + 1, -1);
        return dfs(n);
    }

    int dfs(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;

        if (memo[n] == -1) // 表示之前未计算过
            memo[n] = dfs(n - 1) + dfs(n - 2);

        return memo[n];
    }

    void test_case() {
        int n = 40;
        time_t start = clock();
        int res = fib(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};
