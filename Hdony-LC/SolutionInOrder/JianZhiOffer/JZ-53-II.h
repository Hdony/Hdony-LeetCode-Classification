/*
 * 一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围 0～n-1 之内。
 * 在范围 0～n-1 内的 n 个数字中有且只有一个数字不在该数组中，请找出这个数字。
 *
 * 示例 1:
 * 输入: [0,1,3]
 * 输出: 2
 *
 * 示例 2:
 * 输入: [0,1,2,3,4,5,6,7,9]
 * 输出: 8
 *
 * 限制：
 * 1 <= 数组长度 <= 10000
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int mid, l = 0, r = n; // [l ... r)
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};


