/*
 * 给你一个二进制矩阵 matrix ，它的大小为 m x n ，你可以将 matrix 中的 列 按任意顺序重新排列。
 * 请你返回最优方案下将 matrix 重新排列后，全是 1 的子矩阵面积。
 */

/*
 * 示例 1：
 * 输入：matrix = [[0,0,1],
 *                [1,1,1],
 *                [1,0,1]]
 * 输出：4
 * 解释：你可以按照上图方式重新排列矩阵的每一列。
 * [[0,0,1],     [[0,1,0],
 *  [1,1,1],  ->  [1,1,1],
 *  [1,0,1]]      [1,1,0]]
 * 最大的全 1 子矩阵是上图中加粗的部分，面积为 4 。
 */

/*
 * 示例 2：
 * 输入：matrix = [[1,0,1,0,1]]
 * 输出：3
 * 解释：你可以按照上图方式重新排列矩阵的每一列。
 * 最大的全 1 子矩阵是上图中加粗的部分，面积为 3 。
 */

/*
 * 示例 3：
 * 输入：matrix = [[1,1,0],
 *                [1,0,1]]
 * 输出：2
 * 解释：由于你只能整列整列重新排布，所以没有比面积为 2 更大的全 1 子矩形。
 */

/*
 * 示例 4：
 * 输入：matrix = [[0,0],[0,0]]
 * 输出：0
 * 解释：由于矩阵中没有 1 ，没有任何全 1 的子矩阵，所以面积为 0 。
 */

/*
 * 提示：
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m * n <= 105
 * matrix[i][j] 要么是 0 ，要么是 1 。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>> & matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        for (int j = 0; j < n; ++j)
            for (int i = 1; i < m; ++i)
                if (matrix[i][j]) matrix[i][j] += matrix[i - 1][j];
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < n; ++j)
                ans = max(ans, (j + 1) * matrix[i][j]);
        }
        return ans;
    }

    void test() {
        vector<vector<int>> matrix = {{0,0,1}, {1,1,1}, {1,0,1}};
        cout << largestSubmatrix(matrix);
    }
};





