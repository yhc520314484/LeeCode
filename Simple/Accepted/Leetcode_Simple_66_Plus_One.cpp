/* 
   Leecode 66 Plus_One
   Level: Simple

   Author: JackWilliam
   Date: 18, May, 2020
*/

/*
    Version 0.1   
       注意头插迭代器使用
    4ms  6.9MB
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[digits.size() - 1] += 1;
        while(i > 0){
            if (digits[i] == 10){
                digits[i-1] += 1;
                digits[i] = 0;
            }
            i--;
        }
        if(digits[0] == 10){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};