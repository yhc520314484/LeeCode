/* 
   Leecode m64 qiu-12n-lcof
   Level: Middle

   Author: JackWilliam
   Date: 2, June, 2020
*/

/*
    Version 0.1   
    公式法求解，要想到通过等差数列求取

    0ms      100%
    5.9MB    100%
*/


class Solution {
public:
    int sumNums(int n) {
        return (n + 1) * n / 2;
    }
};
/*
    Other Solution
    Key Point: 枚举中间点

    Source: LeetCode
    Author: orange-32
    Url: https://leetcode-cn.com/problems/qiu-12n-lcof/solution/cjian-dan-dai-ma-shuang-bai-2xing-fu-he-ti-yi-by-o/

    巧用运算符顺序  
    先判断“&&”左侧的表达式，左侧的表达式为真时，再运算右侧的表达式。如左侧为假，则不运算右侧
    关键就在于找出让递归计算停止下来的方法
    0ms  6.1MB
*/
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
