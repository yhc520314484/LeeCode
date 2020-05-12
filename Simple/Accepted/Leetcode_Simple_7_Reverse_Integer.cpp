/* 
   Leecode 7 Reverse Integer
   Level: Simple

   Author: JackWilliam
   Date: 4, May, 2020
*/

/*
    Version 0.1   
       关键在于头文件<limits.h>中  INT_MAX 和 INT_MIN 的使用
    4ms  5.9MB
*/
class Solution {
public:
    int reverse(int x) {
        int res = 0, tmp = 0;
        while(x >= 10 || x <= -10){
            res *= 10;
            tmp = x % 10; 
            res += tmp;
            x /= 10;
        }
        if (res > INT_MAX / 10 || res < INT_MIN / 10)
            res = 0;
        else
            res = res * 10 + x;
        return res;
    }
};