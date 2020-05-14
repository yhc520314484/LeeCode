/* 
   Leecode 500 Keyboard Row
   Level: Simple

   Author: JackWilliam
   Date: 14, May, 2020
*/

/*
    Version 0.1   
       迭代器遍历 注意调用it = nums.erase(it);后迭代器会自动前移

    220ms  7.7MB
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int old = INT_MIN;
        for(auto it = nums.begin(); it != nums.end();){
            if(*it == old) it = nums.erase(it);
            else { old = *it; it++;}
        }
        return nums.size();
    }
};
/*
    Other Solution
    Key Point:双指针法  速度快

    Source: LeetCode
    Author: LeetCode
    Url: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-by-/

    12ms  7.5MB
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
