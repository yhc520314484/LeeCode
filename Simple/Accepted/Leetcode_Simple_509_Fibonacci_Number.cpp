/* 
   Leecode 509 Fibonacci Number
   Level: Simple

   Author: JackWilliam
   Date: 10, June, 2020
*/

/*
    Version 0.1   
    递归
    20 ms        9.98%
    6 MB      100%
*/
class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        else if(N == 1) return 1;
        else return fib(N - 1) + fib(N - 2);
    }
};