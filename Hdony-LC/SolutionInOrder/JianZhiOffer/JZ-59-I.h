/*
 * 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 *
 * 示例:
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7]
 * 解释:

 *   滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 *
 *  提示：
 *  你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <cassert>

using namespace std;


// Using Deque as a Decreasing Queue
// It's a template problem!
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if (k == 0 || nums.empty())
            return vector<int>();

        if (k == 1)
            return nums;

        deque<int> q; //我们需要维护一个单调递减的双向队列
        vector<int> res;
        for (int i = 0 ; i < nums.size() ; i ++){

            while (!q.empty() && q.back() < nums[i])
                q.pop_back();
            q.push_back(nums[i]);

            if (i >= k - 1) {
                res.push_back(q.front());
                if (q.front() == nums[i - (k - 1)])
                    q.pop_front();
            }
        }
        return res;
    }

    void test() {
        vector<int> nums{1,3,-1,-3,5,3,6,7};
        vector<int> res = maxSlidingWindow(nums, 3);
        for (int r : res)
            cout << r << " ";
    }
};
