/* 
   Leecode 100 Same Tree
   Level: Simple

   Author: JackWilliam
   Date: 29, May, 2020
*/

/*
    Version 0.1   
    使用中序遍历分别遍历两个二叉树，将二叉树中的元素依次压入vector中，然后进行对比
    4ms  8.2MB
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> nodeStack_p;
        stack<TreeNode*> nodeStack_q;
        vector<int> vec_p;
        vector<int> vec_q;

        while (!nodeStack_p.empty() || p != nullptr) {
            if(p != nullptr){
                vec_p.push_back(p->val);
                nodeStack_p.push(p);
                p = p->left;
            }
            else{
                vec_p.push_back(NULL);
                p = nodeStack_p.top();
                nodeStack_p.pop();
                p = p->right;
            }
        }

        while (!nodeStack_q.empty() || q != nullptr) {
            if(q != nullptr){
                vec_q.push_back(q->val);
                nodeStack_q.push(q);
                q = q->left;
            }
            else{
                vec_q.push_back(NULL);
                q = nodeStack_q.top();
                nodeStack_q.pop();
                q = q->right;
            }
        }

        if(vec_p.size() != vec_q.size()) return false;
        for(int i = 0; i < vec_p.size(); i++){
            if(vec_p[i] != vec_q[i]) return false;
        }
        return true;
    }
};

/*
    Solution
    Key Point: 递归依次查找 
    时间复杂度 O(N)   空间复杂度O(N)
    4ms   7.4Mb
    Source: LeetCode
    Author: 作者：youlookdeliciousc
    Url: https://leetcode-cn.com/problems/same-tree/solution/c-di-gui-ji-jian-shuang-bai-xie-fa-si-lu-zhu-shi-b/
*/
/*
    验证相同的树，若当前节点都为空，返回true
    若仅有一个节点为空，说明不相同，返回false
    对比当前节点的值，进入递归，p的左子树和q的左子树对比，p的右子树和q的右子树对比
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true; 
        if(!p || !q)    return false; // 说明有且仅有一个为空节点，所以不相同
        return p -> val == q -> val && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};
