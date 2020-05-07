/* 
   Leecode 14 Longest Common Prefix
   Level: Simple

   Author: JackWilliam
   Date: 7, May, 2020
*/

/*
    Version 0.1   
       先找最小子串长度，再找最长公共前缀
    8ms  6.8MB
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if (num == 0) return {};
        else if(num == 1) return strs.at(0);

        string res = {};
        int i = 0;
        int len_min = INT_MAX;

        for(int j = 0; j < num; j++){
            if(strs.at(j).length() == 0) return {}; 
            if(len_min > strs.at(j).length())
            {
                len_min = strs.at(j).length();
            }
        }
        
        do{
            for(int j = 0; j < num - 1; j++){
                if(strs.at(j).at(i) != strs.at(j + 1).at(i)){
                    return res;
                }
            }
            res += strs.at(0).at(i);
            i++;
        }while(i < len_min);
        return res;
    }
};

/*
    Best Solution
    Key Point:3个字符串的最长公共前缀一定被包含在前2个字符串的最长公共前缀之中，
    同理，N个字符串的前缀一定是其中（N-1）个字符串的最长公共前缀与第N个字符串的最长公共前缀

    Source: LeetCode
    Author: 作者：QQqun902025048
    Url: https://leetcode-cn.com/problems/longest-common-prefix/solution/8-xing-c-shun-xu-bi-jiao-by-qqqun902025048/
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs.size() ? strs[0] : "";
        for(auto s: strs){
            while(s.substr(0, r.size()) != r){
                r = r.substr(0, r.size() - 1);
                if(r == "") return r;
            }
        }
        return r;
    }
};
