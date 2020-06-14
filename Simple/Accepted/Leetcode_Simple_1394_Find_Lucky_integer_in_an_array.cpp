/* 
   Leecode 1394 Find Lucky Integer in an Array
   Level: Simple

   Author: JackWilliam
   Date: 12, June, 2020
*/

/*
    Version 0.1   
    排序后计数
    20 ms        37.06%
    10.5 MB      100%
*/
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int count = 1;
        sort(arr.begin(),arr.end());
        for(int i = arr.size() - 1; i > 0;i--){
            if(arr[i] == arr[i - 1]) count++;
            else{
                if(count == arr[i]) return count;
                else count = 1;
            }
        }
        if(count == arr[0]) return count;
        else return -1;
        return -1;
    }
};


/*
    Solution
    Key Point: 使用unordered_map完成
    4 ms          100%
    10.4 MB       100%
    Source: LeetCode
    Author: ding-dang-8
    Url: https://leetcode-cn.com/problems/find-lucky-integer-in-an-array/solution/zhu-yao-shi-shi-yong-unordered_map-ji-lu-mou-ge-sh/
*/
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> numCnt;  // num & num cnt
        int maxLucky = -1;
        for (auto &ele : arr) {
            numCnt[ele]++;
        }
        for (auto &eleNum : arr) {
            if (eleNum == numCnt[eleNum]) {
                maxLucky = max(maxLucky, eleNum);
            }
        }
        return maxLucky;
    }
};
