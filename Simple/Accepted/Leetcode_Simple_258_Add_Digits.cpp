/* 
   Leecode 258 Add Digits
   Level: Simple

   Author: JackWilliam
   Date: 25, May, 2020
*/

/*
    Version 0.1   
       暴力解法,时间复杂度O(n2)
    4ms  6.1MB
*/
class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num >= 10){
            while(1){
                sum = sum + num % 10;
                num = num / 10;
                if(num == 0) break;
            }
            num = sum;
            sum = 0;
        }

        return num;
    }
};
/*
    Other Solution
       Author: shu-ju-jie-gou
       Source:Leetcode
       URL:https://leetcode-cn.com/problems/add-digits/solution/c-shi-jian-fu-za-du-o1de-jie-fa-by-shu-ju-jie-gou-/
       求取树根，时间复杂度O（1）
    0ms  5.9MB
*/
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return (num - 1) % 9 + 1;
    }
};
