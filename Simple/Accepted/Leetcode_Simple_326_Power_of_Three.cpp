/* 
   Leecode 326 Power of Three
   Level: Simple

   Author: JackWilliam
   Date: 5, June, 2020
*/

/*
    Version 0.1   
    递归调用
    28 ms        40.65%
    5.9 MB       100%
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(first == 1){
            first = 0;
            if(n == 0) return false;
        }
        cout << n << endl;
        if(n % 3 == 1 || n % 3 == 2){
            res = 0;
            return false;
        } 
        else if (n % 3 == 0 && n / 3  == 1){
            res = 1;
            return true;
        }
        else isPowerOfThree(n/3); 

        return res;
    }
private:
    int first = 1;
    int res = 0;
};

int main(){
    Solution so;
    bool res;

    res = so.isPowerOfThree(45);
    cout << "res " << res << endl;

    return 0;
}
/*
    Solution
    Key Point: 递归简便写法
    12 ms        96.08%
    5.9 MB       100%
    Source: LeetCode
    Author: lu-guo-de-feng-2
    Url: https://leetcode-cn.com/problems/power-of-three/solution/di-gui-suan-fa-yi-xing-jie-jue-wen-ti-by-lu-guo-de/
*/

class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        if(n <= 0)
            return false;
        else if(n == 1)
            return true;
        else
            return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};

