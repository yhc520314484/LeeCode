/* 
   Leecode 53 Maximum Subarray
   Level: Simple

   Author: JackWilliam
   Date: 26, May, 2020
*/

/*
    Version 0.1   
       空间换时间 通过查表完成
       适当剪枝确保单词中的同一种字母只被检查一次

    0ms  7.2MB
*/

/*
DFS 模板
int check(参数)
{
    if(满足条件)
        return 1;
    return 0;
}
 
void dfs(int step)
{
        判断边界
        {
            相应操作
        }
        尝试每一种可能
        {
               满足check条件
               标记
               继续下一步dfs(step+1)
               恢复初始状态（回溯的时候要用到）
        }
}   
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        string temp = {};
        vector<string> res;
        DFS(s, res, temp,0, 0);
        return res; 
    }
    void DFS(string &s, vector<string> &res, string temp, int start, int step){
        //先设定收敛条件
        if(s.size() == start && step == 4){
            temp.resize(temp.size()-1);
            res.push_back(temp);
            return;
        }

        //剪枝
        if(s.size() - start > (4 - step) * 3) return;
        if(s.size() - start < 4 - step) return;
        int num = 0;
        //状态寻找
        for(int i = start; i < start + 3; i++){
            num = num * 10 + (s[i] - '0');
            if(num <= 255){
                temp+=s[i];
                DFS(s,res,temp+'.',i + 1, step + 1);
            }
            if(num == 0) break;
        }

    }
};

int main(){
    Solution so;
    string input = "25525511135";
    vector<string> res = so.restoreIpAddresses(input);

    for(int i = 0; i < res.size(); i++)
        cout << res.at(i) << endl;
    
    return 0;
}