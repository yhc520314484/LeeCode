/* 
   Leecode 383 Ransom Note
   Level: Simple

   Author: JackWilliam
   Date: 11, June, 2020
*/

/*
    Version 0.1   
    查表
    48 ms        34.55%
    6 MB      100%
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransom_cont['z' + 1] = {0};
        int magazine_cont['z' + 1] = {0};

        for(int i = 0; i < ransomNote.length(); i++){
            ransom_cont[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.length(); i++){
            magazine_cont[magazine[i]]++;
        }

        for(int i = 'a'; i < 'z' + 1; i++){
            if(ransom_cont[i] != 0 && magazine_cont[i] < ransom_cont[i])
                return false;
        }
        return true;
    }
};