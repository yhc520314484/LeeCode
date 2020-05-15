/* 
   Leecode 27 Remove element
   Level: Simple

   Author: JackWilliam
   Date: 15, May, 2020
*/

/*
    Version 0.1   
       迭代器遍历 注意调用it = nums.erase(it);后迭代器会自动前移
        与26题相似
    0ms  6.2MB
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it = nums.begin(); it != nums.end(); ){
            if(*it == val) it = nums.erase(it);
            else it++;
        }
        return nums.size();
    }
};

/*
    Other Solution
    Key Point:双指针法

    12ms  7.5MB
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int num_len= nums.size();
        int i = 0;
        for(int j = 0; j < num_len; j++){
            if(nums[j] != val) {nums[i] = nums[j]; i++;}
        }
        return i;
    }
};