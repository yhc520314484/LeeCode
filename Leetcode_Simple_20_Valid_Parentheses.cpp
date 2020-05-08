/* 
   Leecode 20 Valid Parentheses
   Level: Simple

   Author: JackWilliam
   Date: 8, May, 2020
*/

/*
    Version 0.1   
       关键在于栈的使用
    0ms  6.3MB
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        int len = s.length();
        if(len == 1) return false;

        stack<char> sta {};
        for(int i = 0; i < len; i++){
            switch(s.at(i)){
                case ')':
                    if(sta.empty()) return false;
                    if(sta.top() == '(') sta.pop();
                    else return false; 
                    break;
                case '}':
                    if(sta.empty()) return false;
                    if(sta.top() == '{') sta.pop();
                    else return false; 
                    break;
                case ']':
                    if(sta.empty()) return false;
                    if(sta.top() == '[') sta.pop();
                    else return false; 
                    break;   
                case '(':
                case '[':
                case '{':
                    sta.push(s.at(i));
                    break;
            }
        }
        if(sta.empty()) return true;
        else return false;
    }
};

int main(){
    Solution so;
    bool res = so.isValid("[");
    cout << res << endl;
    
    return 0;
}

