// Created by wuyou on 2021/3/4.

#include <iostream>
#include <vector>

using namespace std;

// Greedy
// Time Complexity: O((m + n) * max(m, n))
// Space Complexity: O(max(m, n))
class Solution1 {
public:
    string largestMerge(string word1, string word2) {

        int n = word1.size(), m = word2.size();

        string res = "";
        int i = 0, j = 0;
        while (i <= n && j <= m) {
            if (i == n) {
                res += word2.substr(j);
                break;
            }
            else if (j == m) {
                res += word1.substr(i);
                break;
            }
            else if (word1[i] > word2[j])
                res += word1[i], i ++;
            else if (word1[i] < word2[j])
                res += word2[j], j ++;
            else if (word1.substr(i + 1) < word2.substr(j + 1))
                res += word2[j], j ++;
            else
                res += word1[i], i ++;
        }
        return res;
    }
};
