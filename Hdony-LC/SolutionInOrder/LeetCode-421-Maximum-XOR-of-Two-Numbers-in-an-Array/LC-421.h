
/*
 * 给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 2^31 。
 * 找到 ai 和 aj 最大的异或 (XOR) 运算结果，其中 0 ≤ i, j < n 。
 * 你能在O(n)的时间解决这个问题吗？
 */

/*
 * 示例:
 * 输入: [3, 10, 5, 25, 2, 8]
 * 输出: 28
 * 解释: 最大的结果是 5 ^ 25 = 28.
 */

/*
 * We can build a prefix tree (Trie) to answer whether there is
 * a number in the array starts with a given substring in O(1)
 */

#include <vector>
#include <bits/unique_ptr.h>

using namespace std;

class Trie {
public:
    Trie(): children(2) {}
    vector<unique_ptr<Trie>> children;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie root;
        auto insert = [&](int num) {
            Trie* node = &root;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1; // 从最高位到最低位 判断是否为 1
                if (!node->children[bit])  // 如果 children[bit] 为空
                    node->children[bit] = make_unique<Trie>(); // 则添加新节点(2个)
                node = node->children[bit].get(); // node 沿着该 children 走下去
            }
        }; // 最终生成 31*2 个节点，线性
        auto query = [&](int num) {
            Trie* node = &root;
            int sum = 0; // 最终返回的结果，即 Maximum XOR
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (node->children[1 - bit]) { // 查看互补位是否存在
                    sum |= (1 << i); // 等价于 sum += 2^i
                    node = node->children[1 - bit].get();
                } else
                    node = node->children[bit].get();
            }
            return sum;
        };

        for (int x : nums) insert(x);

        int ans = 0; // 如果数组中只有一个数字，即自己和自己异或，结果为 0。只要和不同的元素异或，都是大于 0 的，因此和自己异或是最小的。
        for (int x : nums)
            ans = max(ans, query(x));
        return ans;
    }
};





