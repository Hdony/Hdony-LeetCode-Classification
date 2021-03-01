// Created by wuyou on 2021/2/26.

#include <iostream>
#include <vector>

using namespace std;

/*
 * 有 n 个盒子，给你一个长度为 n 的二进制字符串 boxes ，
 * boxes[i] 为 '0' 表示第 i 个盒子是空的，而 boxes[i] 为 '1' 表示盒子里有一个小球。
 * 在一步操作中，你可以将一个小球从某个盒子移动到一个与之相邻的盒子中。
 * 第 i 个盒子和第 j 个盒子相邻需满足 abs(i - j) == 1 。
 * 操作执行后，某些盒子中可能会存在不止一个小球。
 * 返回一个长度为 n 的数组 answer ，其中 answer[i] 是将所有小球移动到第 i 个盒子所需的最小操作数。
 * 每个 answer[i] 都需要根据盒子的初始状态进行计算。
 */

/*
 * 示例 1：
 * 输入：boxes = "110"
 * 输出：[1,1,3]
 * 解释：每个盒子对应的最小操作数如下：
 *   1. 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
 *   2. 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
 *   3. 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。
 * 将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。
 */

/*
 * 示例 2：
 * 输入：boxes = "001011"
 * 输出：[11,8,5,4,3,4]
 */

/*
 * 提示：
 * n == boxes.length
 * 1 <= n <= 2000
 * boxes[i] 为 '0' 或 '1'
 */

/*
 * 解析：
 * dp[i] 代表第 i 个盒子的 minOperations
 * 先求第 0 个盒子，同时记录当前及其右边的 1 的数量
 * 然后依次求 1 到 最后一个盒子，每次向右移动的时候，dp[j] 会比 dp[j-1] 的 minOperations 减少 right 个
 * 需要注意的是如果 boxes[i-1] 是 1 的话，会导致左边的 1 的数量增加，在 left 中补充上左边的 1，
 * 同时当前及其右边的 1 的数量 right 会减少， 最终：dp[j] = dp[j-1] - right + left
 * 比如 boxes = '1011'，
 * 在 index = 0 处，dp[0] = 5, right = 3（包括当前 index = 0 处的 1）
 * 在 index = 1 处，left = 1, right = 2, dp[1] = dp[0] - right + left = 4
 * 依次类推
 */

class MinimumNumberOfOperationsToMoveAllBallsToEachBox {
public:
    vector<int> minOperations(const string& boxes) {

        int n = boxes.size();
        vector<int> dp(n, 0);

        int right = 0;
        for (int i = 0; i < n; i ++) {
            if (boxes[i] == '1') {
                dp[0] += i;
                right += 1; // 当前及其右边 '1' 的数量
            }
        }

        int left = 0;
        for (int j = 1; j < n; j ++) {
            if (boxes[j - 1] == '1') {
                left += 1;
                right -= 1;
            }
            dp[j] = dp[j - 1] - right + left;
        }

        return dp;
    }

    void test() {
        time_t start = clock();
        vector<int> res = minOperations("110");
        time_t end = clock();
        cout << "Result = ";
        for (auto minOps : res)
             cout << minOps << " ";
        cout << endl << "Time = " << double(end - start) / CLOCKS_PER_SEC << endl;
    }
};

