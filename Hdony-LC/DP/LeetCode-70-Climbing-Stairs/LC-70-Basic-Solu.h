// Created by George Wu on 2020/12/20.

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

/*
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * PS：给定 n 是一个正整数。
 */

/*
 * 思路和求斐波那契数列第 n 项相同
 */

// 递归
class ClimbingStairs {
public:
    int climbStairs(int n) {
        return dfs(n);
    }

    // 登上 n 个台阶一共有多少种不同的方法
    int dfs(int n) {

        if (n == 1) return 1; // 爬一个台阶一共有 1 种方法
        if (n == 2) return 2; // 爬一个台阶一共有 2 种方法

        // 爬 n-1 个台阶再爬 1 个台阶 + 爬 n-2 个台阶再爬 2 个台阶
        // 不重复，不遗漏
        return dfs(n - 1) + dfs(n - 2);
    }

    // 爬 35 个台阶
    void test_case(int n = 35) {
        time_t start = clock();
        int res = climbStairs(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

// 记忆化搜索
class ClimbingStairs_Memo {
public:
    vector<int> memo; // memo[i] 爬上 i 个台阶一共有多少种不同的方法
    int climbStairs(int n) {

        memo = vector<int>(n + 1, 0); // memo[0] 表示爬上 0 个台阶有 0 种方法
        return dfs(n);
    }

    int dfs(int n) {

        if (n == 1) return 1;
        if (n == 2) return 2;

        if (memo[n] == 0)
            memo[n] = dfs(n - 1) + dfs(n - 2);

        return memo[n];
    }

    // 爬 35 个台阶
    void test_case(int n = 35) {
        time_t start = clock();
        int res = climbStairs(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

// 动态规划
// O(n), O(n)
class ClimbingStairs_DP {
public:
    int climbStairs(int n) {

        vector<int> memo(n + 1, 0);

        memo[1] = 1;
        memo[2] = 2;

        for (int i = 3; i <= n; i ++)
            memo[i] = memo[i - 1] + memo[i - 2];

        return memo[n];
    }

    // 爬 35 个台阶
    void test_case(int n = 35) {
        time_t start = clock();
        int res = climbStairs(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

// 状态压缩
// O(n), O(1)
class ClimbingStairs_DP_Compress {
public:
    int climbStairs(int n){
        if(n <= 1)
            return n;

        int oneStep = 1; // 当前状态下，再爬 1 个台阶，共有 1 种方法
        int twoStep = 2; // 当前状态下，再爬 2 个台阶，共有 2 种方法
        int curWays;

        for (int i = 3; i <= n; i ++) {
            curWays = oneStep + twoStep; // 当前状态是从状态 oneStep 或 twoStep 得到的
            oneStep = twoStep; // 下一个状态一定是通过 twoStep 和 curWays 得到的，故进行变量替换
            twoStep = curWays;
        }

        return curWays;
    }

    // 爬 35 个台阶
    void test_case(int n = 35) {
        time_t start = clock();
        int res = climbStairs(n);
        time_t end = clock();
        cout << "Result = " << res << endl;
        cout << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};



