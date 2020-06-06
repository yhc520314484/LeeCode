/* 
   Leecode 268 Missing Number
   Level: Simple

   Author: JackWilliam
   Date: 6, June, 2020
*/

/*
    Version 0.1   
    排序后暴力求解
    96 ms        5.81%
    17.3 MB      8.70%
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i != nums[i]) return i;
        }
        return nums.size();
    }
};

/*
    Solution
    Key Point: 等差数列求和
    44 ms        47.34%
    17.1 MB       8.7%
    Source: LeetCode
    Author: chenlele
    Url: https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-gpe3dbjds1/
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=(nums.size()*(nums.size()+1))/2;
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
        }
        return sum;
    }
};

/*
    Solution
    Key Point: 异或
    48 ms        34.77%
    17.1 MB       8.7%
    Source: LeetCode
    Author: chenlele
    Url: https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-gpe3dbjds1/
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            res^=nums[i];
            res^=i;
        }
        return res;
    }
};