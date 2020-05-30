/* 
   Leecode 217 Contains Duplicate
   Level: Simple

   Author: JackWilliam
   Date: 30, May, 2020
*/

/*
    Version 0.1   
    完全暴力，超出时间限制
    64 ms  15.1 MB
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};

/*
    Version 0.2   
    排序后查找
    4ms  8.2MB
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};

/*
    Solution
    Key Point: 利用set对比长度
    112 ms   22.1 Mb
    Source: LeetCode
    Author: QQqun902025048
    Url: https://leetcode-cn.com/problems/contains-duplicate/solution/2xing-c-by-qqqun902025048/
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

/*
    Solution
    Key Point: 利用哈希表
    84 ms   19.5 Mb
    Source: LeetCode
    Author: zrita
    Url: https://leetcode-cn.com/problems/contains-duplicate/solution/c-sortmapsetsan-chong-fang-fa-jian-ji-yi-dong-z-by/
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map <int,int>mp;
        for(int i:nums)
        {
            mp[i]++;  //i对应的value值++

            if(mp[i]>1) //i对应的value值大于1，则说明存在重复元素
                return true;
        }
        return false;
    }
};
