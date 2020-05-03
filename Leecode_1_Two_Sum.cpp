/* 
   Leecode 1 Two sum
   Bruce Force
   The first time to use Leecode
   Author: JackWilliam
   Date: 3, May, 2020
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {   
        vector<int> res = {};
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums.at(i) + nums.at(j) == target){
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};