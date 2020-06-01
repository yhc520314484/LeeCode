/* 
   Leecode 1431 Kids With the Greatest Number of Candies
   Level: Simple

   Author: JackWilliam
   Date: 31, May, 2020
*/

/*
    Version 0.1   
    暴力 时间复杂度O(2N)
    4 ms      84.25% 
    9.1 MB    100%
*/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        vector<bool> res {};
        for(int i = 0; i < candies.size(); i++){
            if(max < candies[i]) max = candies[i];
        }

        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= max) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
