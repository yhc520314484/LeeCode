/* 
   Leecode 53 Maximum Subarray
   Level: Simple

   Author: JackWilliam
   Date: 26, May, 2020

   完全没有思路，一开始考虑了dfs，但不知道该如何做
   后来考虑到了用数组存储所有的结果，但没有想到是动态规划
*/

/*
    Solution 1
    Key Point: 动态规划


    Source: LeetCode
    Author: LeetCode-Solution
    Url: https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
    时间 O(n)  空间O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

/*
    Solution
    Key Point:巧用istringstream  C++STL流


    Source: LeetCode
    Author: xiao-li-ge-6
    Url: https://leetcode-cn.com/problems/length-of-last-word/solution/c-qiao-yong-stream-da-bai-100-by-xiao-li-ge-6/
*/
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        istringstream in(s);
        string res;
        while(in>>res);
        return res.size();
    }
};
