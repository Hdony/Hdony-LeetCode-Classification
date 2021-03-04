#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * 给一个 events 数组，其中 events[i] = [startDayi, endDayi, valuei] ，表示第 i 个会议在 startDayi 天开始，第 endDayi 天结束，
 * 如果你参加这个会议，你能得到价值 valuei 。
 * 同时给你一个整数 k 表示你能参加的最多会议数目。
 * 你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 完整 地参加完这个会议。
 * 会议结束日期是包含在会议内的，也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。
 * 请你返回能得到的会议价值 最大和 。
 */


// DP + Binary Search
// Time Complexity: O(nlogn + nklogn)
// Space Complexity: O(nk)
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());

        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k));

        int res = events[n - 1][2];
        dp[n - 1][0] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i --) {
            dp[i][0] = max(events[i][2], dp[i + 1][0]);
            res = max(res, dp[i][0]);
        }

        for (int j = 1; j < k; j ++) {
            dp[n - 1][j] = events[n - 1][2];
            for (int i = n - 2; i >= 0; i --) {
                dp[i][j] = dp[i + 1][j];
                int x = binary_search(events, i + 1, n - 1, events[i][1] + 1);
                if (x < n)
                    dp[i][j] = max(dp[i][j], events[i][2] + dp[x][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }

private:
    int binary_search(const vector<vector<int>>& events, int L, int R, int t){

        int l = L, r = R + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (events[mid][0] < t)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};





