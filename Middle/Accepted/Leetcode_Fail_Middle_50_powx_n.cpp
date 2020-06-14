/* 
   Leecode 93 Pow_X_N(Can't compelet) 
   Level: Middle

   Author: w-avan
   Source: https://leetcode-cn.com/problems/powx-n/solution/c-ji-bai-shuang-bai-qiao-yong-dui-shu-han-shu-by-w/
   Date: 14, June, 2020
*/

/*
    Version 0.1   
       巧用换底公式

    4ms       43.00%
    6.2MB     100%
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)  return 0;
        double ans;
        if(x > 0 || ((x < 0) && (n % 2 == 0)))    ans = exp(n*log(abs(x)));
        else ans = -exp(n*log(-x));
        return ans;
    }
};

/*
    Solution
    Author: fuxuemingzhu
    Source：LeetCode
    Keypoint: 递归
    Source: https://leetcode-cn.com/problems/powx-n/solution/di-gui-yu-die-dai-by-fuxuemingzhu/

    4ms    43%
    5.8MB  100%
*/
class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
            return 1.0 / myPow(x, -n);
        if (n  % 2 == 1)
            return x * myPow(x, n - 1);
        else {
            double cur = myPow(x, n / 2);
            return cur * cur;
        }
    }
};

/*
    Solution（有点不太明白）
    Author: LeetCode-Solution
    Source：LeetCode
    Keypoint: 迭代
    Source: https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/


*/
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
