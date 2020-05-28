/* 
   Leecode 199 binary tree right side view
   Level: Simple

   Author: JackWilliam
   Date: 28, May, 2020
*/

/*
    Version 0.1   
    参考199题
    12ms  17.1MB
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
    int maxDepth(TreeNode* root) {
        int max_depth = -1;

        stack<TreeNode*> nodeStack;
        stack<int> depthStack;
        nodeStack.push(root);
        depthStack.push(0);

        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();nodeStack.pop();
            int depth = depthStack.top();depthStack.pop();

            if (node != NULL) {
            	// 维护二叉树的最大深度
                max_depth = max(max_depth, depth);

                nodeStack.push(node -> left);
                nodeStack.push(node -> right);
                depthStack.push(depth + 1);
                depthStack.push(depth + 1);
            }
        }
        return max_depth + 1;
    }
};

/*
    Solution
    Key Point: 递归  
    时间复杂度 O(N)   空间复杂度O(log(N))
    16ms   17Mb
    Source: LeetCode
    Author: Gary_coding
    Url: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/c-zhong-gui-zhong-ju-de-8msjie-fa-dfsbfs-shi-jia-2/
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
    Solution
    Key Point: 迭代  
    时间复杂度 O(N)   空间复杂度O(N)
    16ms   17Mb
    Source: LeetCode
    Author: Gary_coding
    Url: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/c-zhong-gui-zhong-ju-de-8msjie-fa-dfsbfs-shi-jia-2/
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ++ans;
        }
        return ans;
    }
};
