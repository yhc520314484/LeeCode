/* 
   Leecode 485 Max Consecutive Ones
   Level: Simple

   Author: JackWilliam
   Date: 12, June, 2020
*/

/*
    Version 0.1   
    简单遍历
    104 ms        24.54%
    33.4 MB      8.33%
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) count++;
            if(max < count) max = count;
            if(nums[i] != 1) count = 0;
        }
        return max;
    }
};