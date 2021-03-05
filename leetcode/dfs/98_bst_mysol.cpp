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

// 오른쪽 트리의 가장 작은 원소보다 작아야하고 왼쪽 트리의 가장 큰 원소보다 커야 한다는 점 추가

class Solution {
public:
    
    TreeNode* travel(TreeNode* root,int direction){     // 1:left, 0: right
        if(direction) return root->left;    
        return root->right;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root->right == nullptr && root->left == nullptr)   return true;
        if(root->right == nullptr && root->left != nullptr){
            if(root->val <= root->left->val)    return false;
            if(!isValidBST(root->left))     return false;   // left subtree isn't true
            TreeNode* final_right = root->left;
            while(final_right -> right != nullptr){
                final_right = travel(final_right,0);   
            }
            return root->val > final_right->val; 
        }
        if(root->right != nullptr && root->left == nullptr){
            if(root->val >= root->right->val)    return false;
            if(!isValidBST(root->right))     return false;
            TreeNode* final_left = root->right;
            while(final_left -> left != nullptr){
                final_left = travel(final_left,1);   
            }
            return root->val < final_left->val; 
        }
        else{
            if(root->val <= root->left->val || root->val >= root->right->val)   return false;
            if(!isValidBST(root->left) || !isValidBST(root->right))  return false;
            TreeNode* final_right = root->left;
            TreeNode* final_left = root->right;
            while(final_right -> right != nullptr){
                final_right = travel(final_right,0);   
            }
            while(final_left -> left != nullptr){
                final_left = travel(final_left,1);   
            }
            return (root->val > final_right->val) && (root->val < final_left->val);
        }
    }
};
