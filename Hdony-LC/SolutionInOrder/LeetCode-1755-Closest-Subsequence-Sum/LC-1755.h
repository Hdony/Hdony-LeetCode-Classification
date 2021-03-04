// Created by wuyou on 2021/3/3.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
 * 题目：
 * 给一个整数数组 nums 和一个目标值 goal 。
 * 需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。
 * 也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal) 。
 * 返回 abs(sum - goal) 可能的 最小值 。
 * 注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
 */

/*
 * 示例 1：
 * 输入：nums = [5,-7,3,5], goal = 6
 * 输出：0
 * 解释：选择整个数组作为选出的子序列，元素和为 6 。
 * 子序列和与目标值相等，所以绝对差为 0 。
 */

/*
 * 示例 2：
 * 输入：nums = [7,-9,15,-2], goal = -5
 * 输出：1
 * 解释：选出子序列 [7,-9,-2] ，元素和为 -4 。
 * 绝对差为 abs(-4 - (-5)) = abs(1) = 1 ，是可能的最小值。
 */

/*
 * 示例 3：
 * 输入：nums = [1,2,3], goal = -7
 * 输出：7
 */

/*
 * 提示：
 * 1 <= nums.length <= 40
 * -107 <= nums[i] <= 107
 * -109 <= goal <= 109
 */

class ClosestSubsequenceSum {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        int ls = half, rs = n - half;

        vector<int> lsum(1 << ls, 0);
        for (int i = 1; i < (1 << ls); i ++) {
            for (int j = 0; j < ls; j ++) {
                if ((i & (1 << j)) == 0)
                    continue;
                lsum[i] = lsum[i - (1 << j)] + nums[j];
                break;
            }
        }
        vector<int> rsum(1 << rs, 0);
        for (int i = 1; i < (1 << rs); i ++) {
            for (int j = 0; j < rs; j ++) {
                if ((i & (1 << j)) == 0)
                    continue;
                rsum[i] = rsum[i- (1 << j)] + nums[ls + j];
                break;
            }
        }
        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());

        int ret = INT_MAX;
        for (int x : lsum)
            ret = min(ret, abs(goal - x));
        for (int x : rsum)
            ret = min(ret, abs(goal - x));

        int i = 0, j = rsum.size() - 1;
        while (i < lsum.size() && j >= 0) {
            int s = lsum[i] + rsum[j];
            ret = min(ret, abs(goal - s));
            if (s > goal)
                j --;
            else
                i ++;
        }
        return ret;
    }

    void test() {
        time_t start = clock();

        vector<int> nums = {7,-9,15,-2};
        int goal = 6;
        int res = minAbsDifference(nums, goal);

        cout << "Result: " << res << endl;
        time_t end = clock();
        cout <<  "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

/*
 *
 */

// Halve and Binary Search
// Time Comelixity: O(2^(n/2) + nlogn)
// Space Complexity: O(2^(n/2))
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {

        // 如果 nums 中只有一个数字，那么只有两个选择：一是选择这个数字，二是不选择这个数字。
        // 选择它，则计算它和 goal 的差，不选它，则 goal 本身就是差
        if (nums.size() == 1) return min(abs(goal), abs(nums[0] - goal));

        int n = nums.size();
        vector<int> a, b; // a 存储 nums 数组中前一半的数字， b 存储后一半的数字
        for (int i = 0; i < n / 2; i ++) a.push_back(nums[i]);
        for (int i = n / 2; i < n; i ++) b.push_back(nums[i]);

        vector<int> A = get(a), B = get(b);
//        for(int e: A) cout << e << " "; cout << endl;
//        for(int e: B) cout << e << " "; cout << endl;
        sort(B.begin(), B.end());

        int res = abs(goal);
        for (int e: A) {
            auto iter = lower_bound(B.begin(), B.end(), goal - e);
            if (iter != B.end()) res = min(res, abs(e + *iter - goal));
            if (iter != B.begin()) {
                iter --;
                res = min(res, abs(e + *iter - goal));
            }
        }
        return res;
    }

private:
    vector<int> get(const vector<int>& nums) {

        int n = nums.size(), p;
        vector<int> res(1 << n, 0);
        for (int i = 1; i < (1 << n); i ++) {
            p = __builtin_ffs(i) - 1;
            res[i] = nums[p] + res[i - (1 << p)];
        }
        return res;
    }
};
