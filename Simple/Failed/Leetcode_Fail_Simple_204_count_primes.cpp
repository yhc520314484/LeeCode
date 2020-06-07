/* 
   Leecode 204 Count Primes
   Level: Simple

   Author: JackWilliam
   Date: 7, June, 2020
*/

/*
    Version 0.1  Failed 
    超出时间限制
*/
class Solution {
public:
    int countPrimes(int n) {
        int res = 1;
        vector<int> maps(n);
        if(n <= 2) return 0;
        for(int i = 3; i < n; i++){
            for(int j = i - 1; j >= 2; j--){
                if(i % j == 0){
                    maps[i] = 1;
                    break;
                }
            }
            if(maps[i] == 0) res++;
        }

        return res;
    }
};

/*
    Solution
    Key Point: 厄拉多塞筛法
    280  ms        33.80%
    6.5 MB         100%
    Source: LeetCode
    Author: magicalchao
    Url: https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-bao-li-fa-ji-you-hua-shai-fa-ji-you/
*/
int countPrimes(int n) {
    int count = 0;
    //初始默认所有数为质数
    vector<bool> signs(n, true);
    for (int i = 2; i < n; i++) {
        if (signs[i]) {
            count++;
            for (int j = i + i; j < n; j += i) {
                //排除不是质数的数
                signs[j] = false;
            }
        }
    }
    return count;
}
