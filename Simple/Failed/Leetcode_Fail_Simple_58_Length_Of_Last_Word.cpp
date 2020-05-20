/* 
   Leecode 58 length-of-last-word Failed
   Level: Simple

   Author: JackWilliam
   Date: 20, May, 2020
*/

/*
    Version 0.1   failed
     情况太多，未考虑清楚
       注意指针回溯
    4ms  6.8MB
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ends = s.length() - 1;
        int str_len = 0;
        if(s.empty()) return 0;

        while(s[ends] == ' '){
            if (ends > 0) ends--;
            else return 0; 
        } 
        if(ends == 0) return s.length();
        //else if(ends != s.length() - 1) ends--;

        for(int i = ends ; i >= 0; i--){
            if(s[i] == ' ') break;
            str_len++;
        }
        return str_len;
    }
};
/*
    Solution
    Key Point:巧用istringstream  C++STL流


    Source: LeetCode
    Author: xiao-li-ge-6
    Url: https://leetcode-cn.com/problems/length-of-last-word/solution/c-qiao-yong-stream-da-bai-100-by-xiao-li-ge-6/
*/
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        istringstream in(s);
        string res;
        while(in>>res);
        return res.size();
    }
};
