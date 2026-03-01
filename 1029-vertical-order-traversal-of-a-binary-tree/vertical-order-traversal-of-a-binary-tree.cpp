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
        vector<vector<int>> ans;
        map<int, map<int,multiset<int>>> mpp;
        queue <pair<TreeNode*, pair<int, int>>> q;
        if(!root) return ans;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* temp = it.first;
            int row = it.second.first;
            int col = it.second.second;
            mpp[row][col].insert(temp->val);
            if(temp->left) q.push({temp->left,{row-1,col+1}});
            if(temp->right) q.push({temp->right,{row+1,col+1}});
        }
        for(auto ver: mpp){
            vector<int> vertical;
            for(auto q: ver.second){
                vertical.insert(vertical.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;

    }
};