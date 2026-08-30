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
  void inorder(TreeNode* root,vector<int>&v){
    if(root==NULL)return ;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
  }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans1;
        inorder(root,ans1);

        int ans=INT_MAX;
        for(int i=1;i<ans1.size();i++){
            ans=min(ans,ans1[i]-ans1[i-1]);
        }
        return ans;
        
    }
};