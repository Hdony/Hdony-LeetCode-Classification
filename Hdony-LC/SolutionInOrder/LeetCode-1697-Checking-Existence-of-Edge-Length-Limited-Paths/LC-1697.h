
/*
 * 给你一个 n 个点组成的无向图边集 edgeList ，
 * 其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi 的边。
 * 请注意，两个点之间可能有 超过一条边 。
 * 给你一个查询数组 queries ，其中 queries[j] = [pj, qj, limitj] ，
 * 你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径，
 * 且这条路径上的每一条边都 严格小于 limitj 。
 * 请你返回一个 布尔数组 answer ，其中 answer.length == queries.length ，
 * 当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false 。
 */

/*
 * 示例 1 ：
 * 输入：n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
 * 输出：[false,true]
 * 解释：上图为给定的输入数据。注意到 0 和 1 之间有两条重边，分别为 2 和 16 。
 * 对于第一个查询，0 和 1 之间没有小于 2 的边，所以我们返回 false 。
 * 对于第二个查询，有一条路径（0 -> 1 -> 2）两条边都小于 5 ，所以这个查询我们返回 true 。
 */

/*
 * 示例 2：
 * 输入：n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
 * 输出：[true,false]
 * 解释：上图为给定数据。
 */

/*
 * 提示：
 * 2 <= n <= 105
 * 1 <= edgeList.length, queries.length <= 105
 * edgeList[i].length == 3
 * queries[j].length == 3
 * 0 <= ui, vi, pj, qj <= n - 1
 * ui != vi
 * pj != qj
 * 1 <= disi, limitj <= 109
 * 两个点之间可能有 多条 边。
 */

/*
 * 解析：
 * 通过 queries 删除掉 edgeList 中不满足的 edge，
 * 并查看 edgeList 中剩下的是否可以连接 query[1] 和 query[0]
 */

#include <vector>
#include <bits/unique_ptr.h>
#include <algorithm>

using namespace std;


class Solution {
    int Father[100005];
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
public:
    int FindFather(int x) {
        if (Father[x] != x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }

    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if (x < y)
            Father[y] = x;
        else
            Father[x] = y;
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for (int i = 0; i < n; i++)
            Father[i] = i;

        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);

        sort(queries.begin(), queries.end(), cmp);
        sort(edgeList.begin(), edgeList.end(), cmp);

        int i = 0;
        vector<bool> ret(queries.size(),0);
        for (auto & q: queries) {
            while (i < edgeList.size() && edgeList[i][2] < q[2]) {
                int a = edgeList[i][0];
                int b = edgeList[i][1];
                if (FindFather(a) != FindFather(b))
                    Union(a,b);
                i ++;
            }
            int idx = q[3];
            ret[idx] = (FindFather(q[0]) == FindFather(q[1]));
        }
        return ret;
    }
};

