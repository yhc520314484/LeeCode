/* 
   Leecode 136 Single Number
   Level: Simple

   Author: JackWilliam
   Date: 24, May, 2020
*/

/*
    Version 0.1   
       暴力解法
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
    Fail Try  
        用栈承装
        无法解决类似[4,1,2,1,2]一类的问题
    16ms  7.4MB
*/
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        stack<int> tmp;

        if(nums.size() == 1) return nums[0];

        for(int i = 0; i < nums.size(); i++){
            if(tmp.empty()){
                tmp.push(nums[i]);
                continue;
            }
            
            if(nums[i] == tmp.top()) tmp.pop();
            else tmp.push(nums[i]);
        }
        
        if(tmp.size() == 1) return tmp.top();
        else{
            for(int i = 0; i < tmp.size() / 2; i++) tmp.pop();
            return tmp.top();
        }
    }
};
*/

/*
    Fail Try  
        超时
*/
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> tmp;

        if(nums.size() == 1) return nums[0];

        for(int i = 0; i < nums.size(); i++){
            if(tmp.empty()){
                tmp.push_back(nums[i]);
                continue;
            }
            int flag = 0;
            for(vector<int>::iterator it=tmp.begin(); it!=tmp.end(); it++){
                if(nums[i] == *it){it = tmp.erase(it);flag = 1;break;}
            }
            if(flag == 0) tmp.push_back(nums[i]);
        }
        return tmp[0];
    }
};
*/

/*
    Solution
    Key Point: 使用unordered_map


    Source: LeetCode
    Author: yizhe-shi
    Url: https://leetcode-cn.com/problems/single-number/solution/c-san-chong-fang-fa-jian-dan-jie-xi-by-yizhe-shi/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        int result = 0;
        for(int i = 0; i < nums.size(); i ++){
            count[nums[i]] ++;
        }
        unordered_map<int, int>::iterator it = count.begin();
        for(; it != count.end(); it ++){
            if(it->second == 1) result = it->first;
        }
        return result;
    }
};


int main(){
    vector<int> exps {4,1,2,1,2};
    Solution so;
    int res;

    res = so.singleNumber(exps);

    cout << res << endl;

    return 0;
}