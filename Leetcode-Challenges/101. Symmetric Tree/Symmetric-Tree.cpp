// Challenge Link: https://leetcode.com/problems/symmetric-tree/


// =================== Solution ===================
// ==== STEPS: ====
// root node
// root->left->val != root->right->val    => return false     <== step 2
// root->left->right, root->right->left   => go to [step 2]
// root->left->left, root->right->right   => go to [step 2]
// until reaching the base case: root->left || root->right don't exist   => return false (if one of them exists and the other doesn't)   OR   true (if both don't exist)

// special case: !node => empty tree => return true


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        bool areMirror(TreeNode* leftNode, TreeNode* rightNode) {
            // base case
            if (!leftNode || !rightNode) 
                return leftNode == rightNode;   // both don't exist
            
            if (leftNode->val != rightNode->val)
                return false;
            
            return areMirror(leftNode->right, rightNode->left) && areMirror(leftNode->left, rightNode->right);
        }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) 
            return true;
        
        return areMirror(root->left, root->right);
    }
};








/*
# Complexity:
-- Time  => O(n)
------ visiting each node once
-- Space => O(log n)
*/