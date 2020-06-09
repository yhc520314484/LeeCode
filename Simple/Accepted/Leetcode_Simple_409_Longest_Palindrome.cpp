/* 
   Leecode 409 Longest Palindrome
   Level: Simple

   Author: JackWilliam
   Date: 9, June, 2020
*/

/*
    Version 0.1   
    有效去重复即可
    0 ms        100%
    6.7 MB      100%
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int alp_count['z' + 1] = {0};
        int single_flag = 0;
        int len = 0;
        for(int i = 0; i < s.length(); i++){
            alp_count[s[i]]++;
        }
        for(int i = 'A', j = 'a'; i <= 'Z'; i++, j++){
            len += alp_count[i];
            len += alp_count[j];
            if(alp_count[i] % 2 != 0) single_flag++;
            if(alp_count[j] % 2 != 0) single_flag++;
        }

        if(single_flag) len = len - single_flag + 1;
        return len;
    }
};
