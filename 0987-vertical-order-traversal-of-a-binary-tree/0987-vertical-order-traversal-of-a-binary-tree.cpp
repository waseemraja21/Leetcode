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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        //  ver => level -> elements
        map<int, map<int, multiset<int>>> mp; // this map will store verticals in sorted order and corresponding to each
        // vertical it will store levels in sorted order and for each level there will be elements in sorted order
        
        
        //          node           ver   level
        queue<pair<TreeNode*, pair<int , int>>> q; //this queue will store nodes and their corresponging vertcals and leveles
        
        q.push({root,{0,0}});// pushing root element with ver : 0 and lev : 0
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int ver = it.second.first;
            int lev = it.second.second;
            
            mp[ver][lev].insert(node->val);       // inserting into map
            
            if(node->left){
                q.push({node->left,{ver-1, lev+1}});
                
            }
            if(node->right){
                q.push({node->right,{ver+1, lev+1}});
            }
            
        }
        
        vector<vector<int>> ans;
        
        for(auto it : mp){  //  here it.first = ver & it.second = (levels=>elements)
            vector<int> temp;
            for(auto i : it.second){ // in first iteration it will be pointing to first levle
                temp.insert(temp.end(),i.second.begin(), i.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};