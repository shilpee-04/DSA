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
    TreeNode* findparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentmap, int start){
        TreeNode* findnode = NULL;

        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            if(curr->val == start) findnode = curr;
            q.pop();
            if(curr->left){
                parentmap[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parentmap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return findnode;
    }
    int timefind(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parentmap, TreeNode* target){
      
        queue <TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int cnt = 0;
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && vis.find(curr->left) == vis.end()){
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right && vis.find(curr->right) == vis.end()){
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(parentmap.count(curr) && vis.find(parentmap[curr]) == vis.end()){
                    q.push(parentmap[curr]);
                    vis.insert(parentmap[curr]);
                }


            }
            cnt++;
            
            
        }
        
        return cnt-1;


    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
     
        unordered_map<TreeNode*, TreeNode*> parentmap;
        TreeNode* target = findparent(root, parentmap, start);
        int ans = timefind(root, parentmap, target);
        return ans;
    }
};