#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 给你一个整数数组 nums 。
 * 一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为 
 * abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。
 * 请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。
 */

/*
 * 示例 1：
 * 输入：nums = [1,-3,2,3,-4]
 * 输出：5
 * 解释：子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
 */

/*
 * 示例 2：
 * 输入：nums = [2,-5,1,-4,3,-2]
 * 输出：8
 * 解释：子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
 */

/*
 * 提示：
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
 */

/*
 * 思路：
 * 1.前缀和
 *   任何子数组的和，其实是某两个位置 (i,j) 前缀和的差值
 *   sum[i:j] = presum[j] - presum[i] (i <= j, 因为某子数组和有实际意义的)
 * 2.某子数组和最大 == 某两个位置 (i,j) 的前缀和的差值 最大 (i <= j)
 *   某子数组和最小 == 某两个位置 (i,j) 的前缀和的差值 最小 (i <= j)
 * 3.但此题是某子数组和的abs最大 == 某两个位置 (i,j) 的前缀和 差距 最大
 *   因为比较的是 差距 ---> 大的 - 小的 就ok了--->i 和 j 相对位置就随意了，不用保持(i <= j)了
 * 4.presum排序--->最大（最后）-最小（最前）--->最大差距！！
 */


// Presum
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();
        // 构建nums的前缀和
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < nums.size(); i ++)
            presum[i + 1] = presum[i] + nums[i];

        int res = 0;

        // 排序过程中找到最小值
        int pmin = 0;
        for (int i = 1; i <= n; i ++) {
            pmin = min(pmin, presum[i - 1]);
            res = max(res, abs(presum[i] - pmin));
        }

        int pmax = 0;
        for (int i = 1; i <= n; i ++) {
            pmax = max(pmax, presum[i - 1]);
            res = max(res, abs(presum[i] - pmax));
        }

        return res;
    }
};

// Presum
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size(), res = 0;

        int pmin = 0, pmax = 0, presum = 0;
        for (int i = 0; i < n; i ++) {
            pmin = min(pmin, presum);
            presum += nums[i];
            res = max(res, abs(presum - pmin));
        }

        presum = 0;
        for (int i = 0; i < n; i ++) {
            pmax = max(pmax, presum);
            presum += nums[i];
            res = max(res, abs(presum - pmax));
        }

        return res;
    }
};












