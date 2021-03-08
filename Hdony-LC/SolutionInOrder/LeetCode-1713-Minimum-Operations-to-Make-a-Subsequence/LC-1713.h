
/*
 * 给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。
 * 每一次操作中，你可以在 arr 的任意位置插入任一整数。
 * 比方说，如果 arr = [1,4,1,2] ，那么你可以在中间添加 3 得到 [1,4,3,1,2] 。
 * 你可以在数组最开始或最后面添加整数。
 * 请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。
 * 一个数组的 子序列 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。
 * 比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的子序列（加粗元素），但 [2,4,2] 不是子序列。
 */

/*
 * 示例 1：
 * 输入：target = [5,1,3], arr = [9,4,2,3,4]
 * 输出：2
 * 解释：你可以添加 5 和 1 ，使得 arr 变为 [5,9,4,1,2,3,4] ，target 为 arr 的子序列。
 */

/*
 * 示例 2：
 * 输入：target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
 * 输出：3
 */

/*
 * 提示：
 * 1 <= target.length, arr.length <= 105
 * 1 <= target[i], arr[i] <= 109
 * target 不包含任何重复元素。
 */

/*
 * target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
 * LCS(target, arr) = [6,8,1] => arr 只需要考虑 [6,8,1], 其他元素无所谓
 */

#include <iostream>
#include <vector>

using namespace std;

// DP
// Time Complexity: O(mn)
// Space Complexity: O(mn) -> O(min(n,m))
class Solution {
private:
    int max3(int a, int b, int c) {
        return max(c, max(a, b));
    }
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        // dp[i][j]: LCS of A[0:i] and B[0:j]
        // dp[i][j] = max{dp[i-1][j],
        //                dp[i][j-1],
        //                dp[i-1][j-1] + A[i]==B[j]}
        int m = target.size(), n = arr.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = max3(dp[i-1][j],
                                dp[i][j-1],
                                dp[i-1][j-1] + int(target[i-1] == arr[j-1]));
        return m - dp[m][n];
    }

    void test() {
        vector<int> target = {6,4,8,1,3,2}, arr = {4,7,6,2,3,8,6,1};
        cout << Solution().minOperations(target, arr);
    }
};

// Optimized (numbers in target are distinct)
// 忽略 target 中没有出现，但是在 arr 中出现的数字 并 将数字转化为索引
// 例如， target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
// 转化为 target = [0,1,2,3,4,5], arr = [1,7删了,0,5,4,2,0,3]
// LCS 的索引 <=> 索引的 最长上升子序列（LIS）
// Time Complexity: O(nlogm)
// Space Complexity: O(2m)
class Solution1 {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        vector<int> arr2idx;
        for (int x : arr) {
            if (count(target.begin(), target.end(), x))
                arr2idx.push_back(*find(target.begin(), target.end(), x));
        }
        return target.size() - lengthOfLIS(arr2idx);
    }

    int lengthOfLIS(vector<int> & nums) {
        vector<int> dp; // dp[i]: 长度为 i 的最长上升子序列的最小末尾数字为 dp[i]
        for (int x : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if (it == dp.end())
                dp.push_back(x);
            else
                *it = x;
        }
        return dp.size(); // 不关心除末尾以外的数字，dp 的长度即为 LIS
    }

    void test() {
        vector<int> target = {6,4,8,1,3,2}, arr = {4,7,6,2,3,8,6,1};
        cout << Solution().minOperations(target, arr);
    }
};







