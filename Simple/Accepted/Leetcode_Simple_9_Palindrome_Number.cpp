/* 
   Leecode 9 Palindrome Number
   Level: Simple

   Author: JackWilliam
   Date: 5, May, 2020
*/

/*
    Version 0.1   
       int 转字符串的应用 to_string
    16ms  5.9MB
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string str=to_string(x);
        int len = str.length();

        for(int i = 0; i < len / 2; i++){
            if (str[i] != str[len - i - 1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution so;
    bool res = so.isPalindrome(1001);
    cout << res << endl;
    
    return 0;
}

