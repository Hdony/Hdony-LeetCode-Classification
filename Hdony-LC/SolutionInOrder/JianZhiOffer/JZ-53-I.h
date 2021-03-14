/*
 * 统计一个数字在排序数组中出现的次数。
 *
 * 示例 1:
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: 2
 *
 * 示例 2:
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: 0
 *
 * 限制：
 * 0 <= 数组长度 <= 50000
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    // 找到 >=target 的左边界，就是满足 nums[i] >= target 里的 i 的最小值
    inline int BinaryLeft(vector<int>& nums, int target) {
        int m, l = 0, r = nums.size() - 1 ;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }

public:
    int search(vector<int>& nums, int target) {
        // 题目假设存在 target，无法额外判断
        // 二分查找都是left边界，等于是前开后闭，这里计算窗口无需额外减1
        return BinaryLeft(nums, target+1) - BinaryLeft(nums, target);
    }
};


