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
