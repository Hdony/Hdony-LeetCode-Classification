/*
 * 输入一个递增排序的数组和一个数字 s ，在数组中查找两个数，使得它们的和正好是 s 。
 * 如果有多对数字的和等于 s ，则输出任意一对即可。
 *
 * 示例 1：
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[2,7] 或者 [7,2]
 *
 * 示例 2：
 * 输入：nums = [10,26,30,31,47,60], target = 40
 * 输出：[10,30] 或者 [30,10]
 *
 * 限制：
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 对撞指针
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target)
                return {nums[l], nums[r]};
            else if (sum > target)
                --r;
            else
                ++l;
        }
        return {};
    }
};
