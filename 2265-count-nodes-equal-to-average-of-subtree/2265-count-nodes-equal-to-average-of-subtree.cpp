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
    int ans = 0;
    pair<int, int> solve(TreeNode* root){

        if(!root){
            return {0,0};
        }

        auto l = solve(root->left);
        auto r = solve(root->right);

        int totalsum = l.first + r.first + root->val;
        int totalcount = l.second + r.second + 1;

        int avg = totalsum/totalcount;

        if(avg == root->val){
            ans++;
        }

        return {totalsum, totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        
        solve(root);
        return ans;
    }
};