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
    TreeNode* build(vector<int>& postorder,int pstart, int pend, vector<int>& inorder, int instart, int inend, unordered_map<int,int> &posmap){
        if(pstart> pend || instart>inend) return NULL;
        TreeNode* curr = new TreeNode(postorder[pend]);
        int idx = posmap[postorder[pend]];
        int cnt_el = idx-instart;
        curr->left = build(postorder,pstart, pstart+cnt_el-1, inorder, instart, idx-1, posmap);
        curr -> right = build(postorder, pstart+cnt_el,pend-1, inorder, idx+1, inend, posmap);
        return curr;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        unordered_map<int,int> posmap;
        for(int i=0;i<inorder.size();i++){
            posmap[inorder[i]] = i;
        }
       
         return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1, posmap);
    }
};