/*
 * 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积,
 * 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
 *
 * 示例:
 * 输入: [1,2,3,4,5]
 * 输出: [120,60,40,30,24]
 *
 * 提示：
 * 所有元素乘积之和不会溢出 32 位整数
 * a.length <= 100000
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size(); // 返回结果的计算
        vector<int> b(n, 1);

        for (int i = 1; i < n; ++i) // 从上到下，左下角的遍历
            b[i] *= b[i - 1] * a[i - 1];

        int accu = 1; // 累计乘积的结果，用于和 b[i] 来计算

        for (int i = n - 2; i >= 0 ; --i) { // 从下到上，右上角的遍历
            accu *= a[i + 1];
            b[i] *= accu;
        }

        return b;
    }

    void test() {
        vector<int> a{1,2,3,4,5,6};
        vector<int> res = constructArr(a);
        for (int i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
};
