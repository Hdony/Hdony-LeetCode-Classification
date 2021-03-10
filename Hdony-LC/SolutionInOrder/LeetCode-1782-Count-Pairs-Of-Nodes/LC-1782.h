
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

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> sizes(n+1, 0);
        vector<unordered_map<int, int>> graph(n + 1);
        for (const vector<int>& edge : edges) {
            graph[edge[0]][edge[1]]++;
            graph[edge[1]][edge[0]]++;
            sizes[edge[0]]++;
            sizes[edge[1]]++;
        }

        vector<int> prefix_sum(100001, 0);
        for (int i = 1; i < sizes.size(); i++) {
            prefix_sum[sizes[i]]++;
        }
        for (int i = 100000; i >= 1; i--) {
            prefix_sum[i-1] += prefix_sum[i];
        }

        vector<int> answer;
        for (int query : queries) {
            int total = 0;

            for (int i = 1; i <= n; i++) {
                const unordered_map<int, int>& mymap = graph[i];

                int target = query - sizes[i];
                int current = 0;
                for (const auto& it : mymap) {
                    int neighbor = it.first;
                    if (sizes[neighbor] > target) {
                        current--;
                    }
                    int count = sizes[i] + sizes[neighbor] - it.second;
                    if (count > query) {
                        current++;
                    }
                }
                if (sizes[i] > target) {
                    current--;
                }
                current += prefix_sum[target < 0 ? 0 : target+1];
                total += current;
            }
            answer.push_back(total / 2);
        }

        return answer;
    }
};


