#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 给一个数组 nums 。nums 的源数组中，所有元素与 nums 相同，但按非递减顺序排列。
 * 如果 nums 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 true ；否则，返回 false 。
 * 源数组中可能存在 重复项 。
 * 注意：我们称数组 A 在轮转 x 个位置后得到长度相同的数组 B ，
 * 当它们满足 A[i] == B[(i+x) % A.length] ，其中 % 为取余运算。
 */

// Linear Scan
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    bool check(vector<int>& nums) {

        int i, n = nums.size();
        for (i = 1; i < n; i ++)
            if (nums[i - 1] > nums[i])
                break;

        if (i == n)
            return true;

        for (int j = i + 1; j < n; j ++)
            if (nums[j - 1] < nums[j])
                return false;

        return nums[0] >= nums.back();
    }
};

