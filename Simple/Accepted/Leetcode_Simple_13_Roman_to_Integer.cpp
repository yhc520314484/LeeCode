/* 
   Leecode 13 Roman to Integer
   Level: Simple

   Author: JackWilliam
   Date: 6, May, 2020
*/

/*
    Version 0.1   
       特例的判断
    12ms  6.4MB
*/
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int res = 0;
        for(int i = 0; i < len; i++){
            switch(s.at(i)){
                case 'I':
                    if(i != len - 1){
                        if(s.at(i + 1) == 'V'){
                            res += 4;
                            i++;
                        }
                        else if(s.at(i + 1) == 'X'){ 
                            res += 9;
                            i++;
                        }        
                        else
                        {
                            res += 1;
                        }  
                    }
                    else
                    {
                        res += 1;
                    }  
                    break;
                case 'X':
                    if(i != len - 1){
                        if(s.at(i + 1) == 'L'){
                            res += 40;
                            i++;
                        }
                        else if(s.at(i + 1) == 'C'){ 
                            res += 90;
                            i++;
                        }        
                        else
                        {
                            res += 10;
                        }
                    }
                    else
                    {
                        res += 10;
                    }  
                    break;      
                case 'C':
                    if(i != len - 1){
                        if(s.at(i + 1) == 'D' && i != len - 1){
                            res += 400;
                            i++;
                        }
                        else if(s.at(i + 1) == 'M' && i != len - 1){ 
                            res += 900;
                            i++;
                        }        
                        else
                        {
                            res += 100;
                        }  
                    }
                    else
                    {
                        res += 100;
                    }  
                    break;    
                case 'V':  
                    res += 5;
                    break;      
                case 'L':  
                    res += 50;
                    break;    
                case 'D':  
                    res += 500;
                    break;     
                case 'M':  
                    res += 1000;
                    break;                                     
            }
        }
        return res;
    }
};

/*
    Best Solution
    Hash map
    Key Point:使用了unordered_map以实现哈希表
    Source: LeetCode
    Author: Gary_coding
    Url: https://leetcode-cn.com/problems/roman-to-integer/solution/c-zhong-gui-zhong-ju-de-4msjie-fa-shu-zu-ha-xi-by-/
    4ms  8MB
*/

class Solution {
private:
    unordered_map<char, int> map = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
public:
    int romanToInt(string s) {
        int ans = 0;
        s += 'I'; //防溢出
        for (int i = 0; i < s.size() - 1; ++i) {
            if (map[s[i]] >= map[s[i + 1]])
                ans += map[s[i]];
            else ans -= map[s[i]];
        }
        return ans;
    }
};