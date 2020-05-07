/* 
   Leecode 1 Two Sum
   Level: Simple

   The first time to use Leetcode
   Author: JackWilliam
   Date: 3, May, 2020
*/

/*
    Version 0.1   
    Bruce Force
    1836ms  7.1MB
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {   
        vector<int> res = {};
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums.at(i) + nums.at(j) == target){
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

/*
    Version 0.2   
    Pair & Sort
    1668ms  8MB
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {   
        vector<int> res = {};
        vector<pair<int,int> > nums_copy;
        for (int i = 0; i < nums.size(); i++)
            nums_copy.push_back(make_pair(nums.at(i), i));
        sort(nums_copy.begin(),nums_copy.end());

        for (int i = 0; i < nums_copy.size(); i++){
            for (int j = i + 1; j < nums_copy.size(); j++){
                if (nums_copy.at(i).first + nums_copy.at(j).first == target){
                    res.push_back(nums_copy.at(i).second);
                    res.push_back(nums_copy.at(j).second);
                    break;
                }
            }
        }
        return res;
    }
};

/*
    Best Solution
    One time Hash map
    Key Point:使用了unordered_map以实现哈希表
    Source: LeetCode
    Author: zrita
    Url: https://leetcode-cn.com/problems/two-sum/solution/c-san-chong-fang-fa-jian-dan-yi-dong-ji-bai-100-z-/
    12ms  8MB
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        /*
            unordered_map内部实现了一个哈希表（也叫散列表，
            通过把关键码值映射到Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1)，
            其在海量数据处理中有着广泛应用）。因此，其元素的排列顺序是无序的  

            对于查找问题，unordered_map会更加高效一些，
            因此遇到查找问题，常会考虑一下用unordered_map    

            unordered_map<Key,Value>   键值对
        */

        unordered_map<int,int> m;
        
        for(int i = 0; i < nums.size(); i++)
        {
            //m中存在对应的键值
            if(m.find(target-nums[i]) != m.end())      
                //m[target-nums[i]]为已经加入map的元素的索引，所以小于本轮循环中的i，放在前面
                //{}通过该符号直接返回vector
                //target-nums[i]是一个Hash Key，坐标i是Value
                return {m[target-nums[i]] , i};        
            
            //向map中添加元素
            m[nums[i]] = i;       
        }
        return {};
    }
};
