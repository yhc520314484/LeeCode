/* 
   Leecode 242 Valid Anagram
   Level: Simple

   Author: JackWilliam
   Date: 4, June, 2020
*/

/*
    Version 0.1   
    查表调用 时间复杂度O(2N)
    8 ms        92.82%
    7.2 MB       100%
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int alpha_map_s['z' + 1] = {0};
        int alpha_map_t['z' + 1] = {0};

        if(s.length() != t.length()) return false;
        if(s.empty() && t.empty()) return true;

        for(int i = 0; i < s.length(); i++){
            alpha_map_t[s[i]] += 1;
            alpha_map_s[t[i]] += 1;
        }
            
        for(int i = 'a'; i < 'z' + 1; i++){
            if(alpha_map_t[i] != alpha_map_s[i])
                return false;
        }   
        return true;
    }
};

/*
    Solution
    Key Point: 对s和t进行排序，若字母数量一样，排序后结果应该一样 但损失了一定的速度
    80 ms          16.09%
    7.6 MB       100%
    Source: LeetCode
    Author: 作者：zrita
    Url: https://leetcode-cn.com/problems/valid-anagram/solution/c-gou-jian-liang-ge-ha-xi-shu-zu-jian-ji-yi-dong-8/
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
};
