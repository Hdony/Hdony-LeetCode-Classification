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

    void test_case(int n = 40) {
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

        if (memo[n] == -1) // 表示之前未计算过；设置为 -1 的原因在于 memo[i] 永远不会被赋值为 -1
            memo[n] = dfs(n - 1) + dfs(n - 2);

        return memo[n];
    }

    void test_case(int n = 40) {
        time_t start = clock();
        int res = fib(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

// 动态规划（用一个数组记录重复计算的内容--重叠子问题）
class Fibonacci_DP {
public:
    int fib(int n) {
        vector<int> memo(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i <= n; i ++)
            memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }

    void test_case(int n = 0) {
        time_t start = clock();
        int res = fib(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

