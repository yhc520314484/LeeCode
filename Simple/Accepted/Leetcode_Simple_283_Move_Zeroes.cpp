/* 
   Leecode 283 Move Zeros
   Level: Simple

   Author: JackWilliam
   Date: 3, June, 2020
*/

/*
    Version 0.1   
    迭代器的调用
    12 ms        49.14%
    9.1 MB       100%
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (auto it = nums.begin(); it < nums.end(); ){
            if(*it == 0){
                it=nums.erase(it);
                i++;
            }
            else *it++;
        }
        for(;i > 0; i--) nums.push_back(0);
    }
};

/*
    Solution
    Key Point: 双指针法
    4 ms          98.47%
    9.1 MB       100%
    Source: LeetCode
    Author: lo_e
    Url: https://leetcode-cn.com/problems/move-zeroes/solution/shuang-zhi-zhen-jiao-huan-yuan-su-by-lo_e/
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        for(i=0,j=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
}; 
