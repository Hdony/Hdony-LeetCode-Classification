
/*
 * 给你一个无向图，无向图由整数 n ，表示图中节点的数目，和 edges 组成，
 * 其中 edges[i] = [ui, vi] 表示 ui 和 vi 之间有一条无向边。
 * 同时给你一个代表查询的整数数组 queries 。
 * 第 j 个查询的答案是满足如下条件的点对 (a, b) 的数目：
 *   a < b
 *   cnt 是与 a 或者 b 相连的边的数目，且 cnt 严格大于 queries[j] 。
 * 请你返回一个数组 answers ，其中 answers.length == queries.length
 * 且 answers[j] 是第 j 个查询的答案。
 * 请注意，图中可能会有 重复边 。
 *
 * 示例 1：
 * 输入：n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
 * 输出：[6,5]
 * 解释：每个点对中，与至少一个点相连的边的数目如上图所示。
 *
 *
 * 示例 2：
 * 输入：n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
 * 输出：[10,10,9,8,6]
 
 * 提示：
 * 2 <= n <= 2 * 10^4
 * 1 <= edges.length <= 10^5
 * 1 <= ui, vi <= n
 * ui != vi
 * 1 <= queries.length <= 20
 * 0 <= queries[j] < edges.length
 */

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> count(n); // count[i] 表示 与节点 i 相连的边数
        unordered_map<long, int> edgeCount;
        long M = 20001;

        for (auto edge: edges) {
            int a = min(edge[0] - 1, edge[1] - 1); // 节点序号从 0 开始
            int b = max(edge[0] - 1, edge[1] - 1);
            count[a] ++;
            count[b] ++;
            edgeCount[a * M + b] ++; // 节点对 {a,b} 有几个（用哈希值与 {b,a} 区分）
        }

        auto count2 = count;
        sort(count2.begin(), count2.end());

        vector<int> rets;
        for (int q : queries) {
            int sum = 0; // 大于 q 的点对数
            int j = n - 1;
            // 利用双指针从两端向中间移动，统计 count[a] + count[b] > q 的节点对数
            for (int i = 0; i < n; i++) { // i 为左指针，j 为右指针
                if (i >= j)
                    sum += n - i - 1;
                else {
                    while (i < j && count2[i] + count2[j] > q)
                        j --;
                    sum += n - j - 1;
                }
            }

            for (auto [edgeIdx, cnt] : edgeCount) {
                int a = edgeIdx / M;
                int b = edgeIdx % M;
                if (count[a] + count[b] > q && count[a] + count[b] - cnt <= q)
                    sum --;
            }
            rets.push_back(sum);
        }
        return rets;
    }

    void test() {
        int n = 5;
        vector<vector<int>> edges = {{1,5},{1,5},{3,4},{2,5},{1,3},{5,1},{2,3},{2,5}};
        vector<int> queries = {1,2,3,4,5};
        auto ans = countPairs(n, edges, queries);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
        // [10,10,9,8,6]
    }
};


