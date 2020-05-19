/* 
   Leecode 66 Add Binary
   Level: Simple

   Author: JackWilliam
   Date: 19, May, 2020
*/

/*
    Version 0.1   
       注意大小端模式，字符串注意反转
    4ms  6.4MB
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int up = 0;
        string tmp{};



        if(b.length() > a.length()){
            tmp = std::move(a);
            a = std::move(b); 
            b = std::move(tmp);
        }
        
        reverse(a.begin(),a.end());  
        reverse(b.begin(),b.end());  

        for(int i = 0; i < b.length(); i++){
            int bit_now = (a[i] - '0') + (b[i] - '0') + up;
            switch(bit_now){
                case 0:
                    a[i] = '0';
                    up = 0;
                    break; 
                case 1:
                    a[i] = '1';
                    up = 0;
                    break; 
                case 2:
                    a[i] = '0';
                    up = 1;
                    break; 
                case 3:
                    a[i] = '1';
                    up = 1;
                    break; 
            }
        }
        for(int i = b.length(); i < a.length(); i++){
            int bit_now = (a[i] - '0') + up;
            if (bit_now == 2){
                a[i] = '0';
                up = 1;
            }
            else{
                a[i] = bit_now + '0';
                up = 0;
            } 
        }
        if(up == 1){
            tmp = "1";
            a = a + tmp;
        }
        reverse(a.begin(),a.end());  
        return a;
    }
};