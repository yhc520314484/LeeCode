/* 
   Leecode 771 Jewels_and_Stones
   Level: Simple

   Author: JackWilliam
   Date: 21, May, 2020
*/

/*
    Version 0.1   
       查表即可
    0ms  6.3MB
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jew_maps[123] = {0};

        for(int i = 0; i < J.length(); i++){
            jew_maps[J[i]] = 1;
        }
        int jew_count = 0;
        for(int i = 0; i < S.length(); i++){
            if(jew_maps[S[i]] == 1) jew_count++;
        }
        return jew_count;
    }
};
