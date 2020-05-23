/* 
   Leecode 125 Valid Palindrome
   Level: Simple

   Author: JackWilliam
   Date: 23, May, 2020
*/

/*
    Version 0.1   
       暴力解法
    16ms  7.4MB
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        string str = s;
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                str[j] = s[i] + 32;
                j++;
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                str[j] = s[i];
                j++;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                str[j] = s[i];
                j++;
            }
        }
        if(j == 1) return true;
        for(int i = 0; i < j / 2; i++){
            if(str[i] != str[j - i - 1]) return false;
        }
        return true;
    }
};

/*
    Other Solution
       双指针法，受leetcode主流题解影响
       注意下标在循环中的移动写法
    8ms  7.5MB
*/

class Solution {
public:
    char isVaild(char c){
        if(c >= 'A' && c <= 'Z'){
            c = c + 32;
            return c;
        }
        else if(c >= 'a' && c <= 'z') return c;
        else if(c >= '0' && c <= '9') return c;
        else return ' ';  
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        char left, right;
        for(i = 0; i < j; ){
            left = isVaild(s[i]);
            if(left == ' '){
                i++; continue;
            }
            right = isVaild(s[j]);
            if(right == ' '){
                j--; continue;
            }
            if(left != right) return false;
            j--;
            i++;           
        }
        return true;
    }
};