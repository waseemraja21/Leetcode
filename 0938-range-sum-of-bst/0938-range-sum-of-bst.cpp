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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) continue;
            int rootVal = node->val;
        
            
            if(rootVal >= low && rootVal <= high){
                ans += rootVal;
                q.push(node->left);
                q.push(node->right);
            }else if(rootVal < low){
                if(node->right) q.push(node->right);
            }else if(rootVal > high){
                if(node->left) q.push(node->left);
            }
        }
        return ans;
    }
};