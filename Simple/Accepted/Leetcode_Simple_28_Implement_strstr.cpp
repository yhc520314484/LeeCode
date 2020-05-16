/* 
   Leecode 28 implement-strstr
   Level: Simple

   Author: JackWilliam
   Date: 16, May, 2020
*/

/*
    Version 0.1   
       注意指针回溯
    4ms  6.8MB
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int j = 0;
        for(int i = 0; i < haystack.length(); i++){
            if (haystack[i] == needle[j++]){
                if(j == needle.length()) return i - j + 1;
                else continue;
            }
            else{i = i - j + 1;j = 0; }
        }
        return -1;
    }
};


int main(){
    Solution so;
    int res = so.strStr("mississippi", "issi");
    cout << res << endl;
    
    return 0;
}

