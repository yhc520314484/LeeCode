/* 
   Leecode 35 Search_Insert_Position
   Level: Simple

   Author: JackWilliam
   Date: 17, May, 2020
*/

/*
    Version 0.1   
       注意迭代器使用
    4ms  6.9MB
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= target){
                nums.insert(nums.begin()+i,target);
                return i;
            }
            if(i == nums.size() - 1){
                nums.insert(nums.end(),target);
                return nums.size() - 1;                
            }
        }
        return 0;
    }
};
