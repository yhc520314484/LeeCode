/* 
   Leecode 500 Keyboard Row
   Level: Simple

   Author: JackWilliam
   Date: 10, May, 2020
*/

/*
    Version 0.1   
       空间换时间 通过查表完成
       适当剪枝确保单词中的同一种字母只被检查一次

    0ms  7.2MB
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string line1 = "qwertyuiop";
        string line2 = "asdfghjkl";
        string line3 = "zxcvbnm";
        vector<string> res {};

        int words_num = words.size();
        
        for(int i = 0; i < words_num; i++){
            string flag = "00000000000000000000000000";
            char nop_flag = 0;
            char same = '0';
            for(int j = 0; j < words.at(i).length(); j++){
                int tmp = words.at(i).at(j);

                if(tmp >= 'A' && tmp <= 'Z') tmp = tmp + 32;
                int real_tmp = tmp;
                tmp = tmp - 'a';

                if(flag.at(tmp) == '0'){
                    if(line1.find(real_tmp) != string::npos) flag.at(tmp) = '1';
                    else if(line2.find(real_tmp) != string::npos) flag.at(tmp) = '2';
                    else flag.at(tmp) = '3'; 
                }
            }
            for(int j = 0; j < flag.length(); j++){

                if (flag.at(j) != '0' && same == '0') same = flag.at(j);
                else if (flag.at(j) != '0' && same != flag.at(j)){
                    nop_flag = 1;
                    break;
                }
            }              
            if (nop_flag == 1) continue;
            res.push_back(words.at(i));
        }

        return res;
    }
};

int main(){
    Solution so;
    vector<string> input= {"qz","wq","asdddafadsfa","adfadfadfdassfawde"};
    vector<string> res = so.findWords(input);

    for(int i = 0; i < res.size(); i++)
        cout << res.at(i) << endl;
    
    return 0;
}

/*
    Other Solution
    Key Point:将所有大小写字母存入哈希表，直接查找判断

    Source: LeetCode
    Author: llllllll-9
    Url: https://leetcode-cn.com/problems/keyboard-row/solution/ha-xi-biao-shuang-100-by-llllllll-9/
*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> map1={{'q',0},{'w',0},{'e',0},{'r',0},{'t',0},{'y',0},{'u',0},{'i',0},{'o',0},{'p',0},{'a',1},{'s',1},{'d',1},{'f',1},{'g',1},{'h',1},{'j',1},{'k',1},{'l',1},{'z',2},{'x',2},{'c',2},{'v',2},{'b',2},{'n',2},{'m',2},{'Q',0},{'W',0},{'E',0},{'R',0},{'T',0},{'Y',0},{'U',0},{'I',0},{'O',0},{'P',0},{'A',1},{'S',1},{'D',1},{'F',1},{'G',1},{'H',1},{'J',1},{'K',1},{'L',1},{'Z',2},{'X',2},{'C',2},{'V',2},{'B',2},{'N',2},{'M',2}};
        vector<string> vec;//存放最终结果
        string str;//暂存中间某个字符串
        int k,flat;
        for(int i=0;i<words.size();i++){
            str=words[i];
            k=map1[str[0]];//获取首字母所在的行
            if(str.size()==1) vec.push_back(str);//只有一个字母的特例
            else{
                flat=0;
                for(int j=1;j<str.size();j++){
                    if(map1[str[j]]!=k){
                        flat=1;
                        break;
                    }
                }
                if(flat==0) vec.push_back(str);//若每个字符都在k行，则将此字符串存入vec中              
            }

        }
        return vec;
    }
};
