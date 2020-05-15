/* 
   Leecode 17 Remove element
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
    int removeDuplicates(vector<int>& nums) {
        int old = INT_MIN;
        for(auto it = nums.begin(); it != nums.end();){
            if(*it == old) it = nums.erase(it);
            else { old = *it; it++;}
        }
        return nums.size();
    }
};
