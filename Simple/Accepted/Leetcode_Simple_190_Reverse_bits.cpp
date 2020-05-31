/* 
   Leecode 190 Reverse_bits
   Level: Simple

   Author: JackWilliam
   Date: 31, May, 2020
*/

/*
    Version 0.1   
    调用各种STL库函数完成
    4 ms  6.4 MB
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> t;
        t = n;
        string str=t.to_string();
        reverse(str.begin(),str.end());

        uint32_t res = 0;
        for(int i = 0; i < str.size(); i++)
            if(str[i] == '1') res += pow(2.0, 31 - i);

        return res;
    }
};


/*
    Solution
    Key Point: 使用位运算
    4 ms   5.9 Mb
    Source: LeetCode
    Author: li-ke-sen
    Url: https://leetcode-cn.com/problems/reverse-bits/solution/li-yong-wei-cao-zuo-jie-ti-qian-xian-yi-dong-by-li/
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i = 31; i >= 0; i--) {
            ret = ret | (((n>>(31-i)) & 1) << i);
        }

        return ret;
    }
};