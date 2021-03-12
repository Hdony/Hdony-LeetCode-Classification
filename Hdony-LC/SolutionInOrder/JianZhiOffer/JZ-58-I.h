/*
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 * 为简单起见，标点符号和普通字母一样处理。
 * 例如输入字符串 "I am a student. "，则输出 "student. a am I"。
 *
 * 示例 1：
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 *
 * 示例 2：
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 *
 * 示例 3：
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 * 说明：
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


/// Split and Reverse
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    void reverseWords(string &s) {
        vector<string> vec = split(s);
        if (vec.size() == 0) {
            s = "";
            return;
        }

        reverse(vec.begin(), vec.end());
        s = vec[0];
        for(int i = 1; i < vec.size() ; i ++)
            s += " " + vec[i];
    }

private:
    vector<string> split(const string& s){

        vector<string> res;

        int start = nextNonSpace(s, 0);
        for(int i = start + 1; i <= s.size() ;)
            if(i == s.size() || s[i] == ' ') {
                res.push_back(s.substr(start, i - start));
                start = nextNonSpace(s, i);
                i = start + 1;
            }
            else
                i ++;

        return res;
    }

    int nextNonSpace(const string& s, int start){
        int i = start;
        for(; i < s.size() ; i ++)
            if(s[i] != ' ')
                return i;
        return i;
    }
};

