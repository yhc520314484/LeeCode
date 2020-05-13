/* 
   Leecode 1307 Verbal Arithmetic Puzzle(Can't compelet) 
   Level: Hard

   Date: 13, May, 2020
*/

/*
    Version 0.1   
       DFS leetcode中遇到的第二道DFS 
       看到题目就想到了DFS 但不知道如何实现
       本次的进步是想到了unordered_map 回溯剪枝
       但没有想到回溯剪枝的具体实现方法
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

/*
    Solution
    Key Point:分析清楚剪枝与回溯的条件

    Pending： 未能理解效果

    Source: LeetCode
    Author: xyqkoala
    Url: https://leetcode-cn.com/problems/verbal-arithmetic-puzzle/solution/hui-su-jian-zhi-by-xyqkoala/
*/
class Solution {
public:
    // check最高位为num位（个位为0位，十位为1位...）
    int check(int num,vector<int> &re,vector<string> &words,string &result,unordered_map<char,int> &t){
        int add = 0;	// 进位值
        for(int i =0;i<=num;i++){
            int ts = re[t[result[i]]];
            int tts = add;
            for(auto &str:words){
                int tn = str.size();
                int x = 0;
                if(i<tn) x = re[t[str[i]]];
                tts += x;
            }
            add = tts/10;
            tts = tts%10;
            if(tts!=ts) return 0;
        }
        if((num+1)==result.size() && add == 0) return 2;	// 生成完成且条件满足
        return 1;	// 条件满足，但未生成完毕
    }
    bool dfs(int &mask,int &n,vector<int> &re,vector<string> &words,string &result,unordered_map<char,int> &t,unordered_map<int,int> & tt){
        if(tt.find(re.size()) != tt.end()){ // 一个新的高位产生

            int num = tt[re.size()];
            int tre = check(num,re,words,result,t);
            // 前num个数字的排列不合适，剪枝
            if(tre == 0) return false;
            // 前num个数的排列合适，而且已经生成了所有数
            if(tre == 2) return true;
        }
        for(int i = 0;i<10;i++){
            int tm = (1 << i);
            if(mask&tm) continue;
            re.push_back(i);
            mask += tm;
            if(dfs(mask,n,re,words,result,t,tt)) return true;
            mask-=tm;
            re.pop_back();
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        unordered_map<char,int> t;
        unordered_map<int,int> tt;
        int idx = 0;
        reverse(result.begin(),result.end());
        int n = result.size();
        for(auto &str:words){
            reverse(str.begin(),str.end());
        }
        for(int i = 0;i<n;i++){
            if(t.find(result[i]) == t.end()) t[result[i]] = idx++;
            for(auto &str:words){
                int tn = str.size();
                if(i>=tn) continue;
                if(t.find(str[i]) == t.end()) t[str[i]] = idx++;
            }
            tt[idx] = i;
        }
        int mask = 0;
        vector<int> re;
        return dfs(mask,idx,re,words,result,t,tt);
    }
};
