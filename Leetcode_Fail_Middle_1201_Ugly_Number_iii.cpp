/* 
   Leecode 1201 Ugly_Number_iii (超时)
   Level: Middle

   Author: 参考CSDN“lang的飞起”所给出的题解后完成
   Source: https://blog.csdn.net/qq_31726419/article/details/78204207
   Date: 11, May, 2020
*/

/*
    Version 0.1   
       想到了时间换空间，但定义出来的数组过大，且无法规避超时问题
       使用暴力方法，引发超时
*/


#include <iostream>
#include <ctime>

#include<algorithm>

using namespace std;

// 纯暴力做法  超时 
// n = 1000000000, a = 2, b = 217983653, c = 336916467; 9113ms
/*
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        const unsigned int arr_size = 2 * 1000000000;

        unsigned int i = 1;
        int count = 0;

        while(i < arr_size){
            if(i % a == 0) count++;
            else if(i % b == 0) count++;
            else if(i % c == 0) count++;
            if(count == n) return i;
            i++;
        }

        return 0;
    }
};
*/

/*
    Solution
    Key Point:想到二分查找，并排除丑数因子！

    Source: LeetCode
    Author: Alfeim
    Url: https://leetcode-cn.com/problems/ugly-number-iii/solution/er-fen-fa-si-lu-pou-xi-by-alfeim/
*/
class Solution {
public:
    using LL = long long;

    int nthUglyNumber(int n, int a, int b, int c) {
        //看到n的范围应该马上联想到是，典型的二分思路
        LL low = min(min(a,b),c);                            //下边界显然是a、b、c中最小者
        LL high = static_cast<LL>(low) * n;                 //上边界是这个最小者的n倍
        
        LL res = Binary_Search(low,high,a,b,c,n);

        LL left_a = res%a;
        LL left_b = res%b;
        LL left_c = res%c;

        return res - min(left_a,min(left_b,left_c));
    }
    
    //二分搜索
    LL Binary_Search(LL low,LL high,int a,int b,int c,LL n){
        if(low >= high) return low;

        LL mid = (low + high)>>1;

        LL MCM_a_b = MCM(a,b);
        LL MCM_a_c = MCM(a,c);
        LL MCM_b_c = MCM(b,c);
        LL MCM_a_b_c = MCM(MCM_a_b,c);

        //独立的丑数个数为，当前数分别除以a、b、c的和，减去当前数除以a、b、c两两间最小公倍数的和，再加上当前数除以 a、b、c三者的最小公倍数
        LL count_n = mid/a + mid/b + mid/c - mid/MCM_a_b - mid/MCM_b_c - mid/MCM_a_c +  mid/MCM_a_b_c;
        
        if(count_n == n) return mid;
        
        if(count_n < n) return Binary_Search(mid + 1,high,a,b,c,n);

        return Binary_Search(low,mid-1,a,b,c,n);
    }

    //求最小公倍数：两数乘积除以最大公约数
    LL MCM(LL a,LL b){
        
        LL Multi = a * b;
        
        while(b > 0){
            LL tmp = a % b;
            a = b;
            b = tmp;
        }

        return Multi/a;
    }

};


int main(){
    Solution so;
    int n = 1000000000, a = 2, b = 217983653, c = 336916467;

    clock_t start, finish;
    start = clock();
    int res = so.nthUglyNumber(n,a,b,c);
    finish = clock();

    cout << "res " << res << endl;
    cout << "time " << (double)(finish - start) << endl;
    
    return 0;
}
