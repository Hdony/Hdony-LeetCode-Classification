/*
 * 0,1,···,n-1 这 n 个数字排成一个圆圈，从数字 0 开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
 * 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 *
 * 示例 1：
 * 输入: n = 5, m = 3
 * 输出: 3
 *
 * 示例 2：
 * 输入: n = 10, m = 17
 * 输出: 2
 *
 * 限制：
 * 1 <= n <= 10^5
 * 1 <= m <= 10^6
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    // 长度为 n 的序列会先删除第 m % n 个元素
    int f(int n, int m) {
        if (n == 1)
            return 0;
        int x = f(n - 1, m); // 最终会留下第几个元素
        return (m + x) % n;
    }
public:
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (m + ans) % i;
        }
        return ans;
    }
};
