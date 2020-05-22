/* 
   Leecode 93 Count Number of Teams
   Level: Middle

   Author: JackWilliam
   Date: 22, May, 2020
*/

/*
    Version 0.1   
    纯暴力解法 时间复杂度太高（N3）

    196ms  7.4MB
*/


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;

        for(int i = 0; i < rating.size() - 2; i++){
            for(int j = i + 1; j < rating.size() - 1; j++){
                for(int k = j + 1; k < rating.size(); k++){
                    if((rating[i] > rating[j] && rating[j] > rating[k]) || (rating[i] < rating[j] && rating[j] < rating[k]))
                        res++;
                }
            }
        }

        return res;
    }
}

/*
    Other Solution
    Key Point: 枚举中间点

    Source: LeetCode
    Author: leetcode-solution
    Url: https://leetcode-cn.com/problems/count-number-of-teams/solution/tong-ji-zuo-zhan-dan-wei-shu-by-leetcode-solution/

    时间复杂度 N2
    8ms  7.6MB
*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        // 枚举三元组中的 j
        for (int j = 1; j < n - 1; ++j) {
            int iless = 0, imore = 0;
            int kless = 0, kmore = 0;
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    ++iless;
                }
                // 注意这里不能直接写成 else
                // 因为可能有评分相同的情况
                else if (rating[i] > rating[j]) {
                    ++imore;
                }
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    ++kless;
                }
                else if (rating[k] > rating[j]) {
                    ++kmore;
                }
            }
            ans += iless * kmore + imore * kless;
        }
        return ans;
    }
};

/*
    Other Solution
    Key Point: 离散化树状数组

    pendding：暂未理解

    Source: LeetCode
    Author: leetcode-solution
    Url: https://leetcode-cn.com/problems/count-number-of-teams/solution/tong-ji-zuo-zhan-dan-wei-shu-by-leetcode-solution/

    时间复杂度 NlogN
    4ms  8.1MB
*/

class Solution {
public:
    static constexpr int MAX_N = 200 + 5;

    int c[MAX_N];
    vector <int> disc;
    vector <int> iLess, iMore, kLess, kMore;

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int p, int v) {
        while (p < MAX_N) {
            c[p] += v;
            p += lowbit(p);
        }
    }

    int get(int p) {
        int r = 0;
        while (p > 0) {
            r += c[p];
            p -= lowbit(p);
        }
        return r;
    }

    int numTeams(vector<int>& rating) {
        disc = rating;
        disc.push_back(-1);
        sort(disc.begin(), disc.end());
        auto getId = [&] (int target) {
            return lower_bound(disc.begin(), disc.end(), target) - disc.begin();
        };


        iLess.resize(rating.size());
        iMore.resize(rating.size());
        kLess.resize(rating.size());
        kMore.resize(rating.size());

        for (int i = 0; i < rating.size(); ++i) {
            auto id = getId(rating[i]);
            iLess[i] = get(id);
            iMore[i] = get(201) - get(id); 
            add(id, 1);
        }

        memset(c, 0, sizeof c);
        for (int i = rating.size() - 1; i >= 0; --i) {
            auto id = getId(rating[i]);
            kLess[i] = get(id);
            kMore[i] = get(201) - get(id); 
            add(id, 1);
        }
        
        int ans = 0;
        for (unsigned i = 0; i < rating.size(); ++i) {
            ans += iLess[i] * kMore[i] + iMore[i] * kLess[i];
        }

        return ans;
    }
};

