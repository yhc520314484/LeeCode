/* 
   Leecode 93 Restore IP Addresses(Can't compelet) 
   Level: Middle

   Author: 参考CSDN“lang的飞起”所给出的题解后完成
   Source: https://blog.csdn.net/qq_31726419/article/details/78204207
   Date: 11, May, 2020
*/

/*
    Version 0.1   
       DFS leetcode中遇到的第一道DFS 
       看到题目就想到了DFS 但不知道如何实现
       写的代码还是太少了
       关键在于先把问题分析清楚，各种情况，跳出条件等

    0ms  6.6MB
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
    vector<string> restoreIpAddresses(string s) {
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

/*
这样写为什么允许了单个0而排除了连续0？
只用了if(num==0) break;这一条语句，要执行这条语句，必须要从上面的DFS递归中返回

若当前为单个0，则满足<=255，进入递归，递归返回后，表示这部分为单个0的所有可能已经处理完了

若向后循环，则可能出现这一部分为连续0,0后跟数字(000,001)这些都不能作为IP地址4部分的1部分，故直接break就好
*/