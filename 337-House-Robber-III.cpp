
class Solution {
public:
    map<pair<TreeNode*,int>,int>mp;
    int f(TreeNode* root,int z){
        if(!root) return 0;

        if(mp.find({root,z})!=mp.end())
            return mp[{root,z}];
        if (z == 0) {
            int l = f(root->left, 1);
            int r = f(root->right, 1);
            return mp[{root,z}] = l + r;
        }
        else {
            int l = f(root->left, 0);
            int r = f(root->right, 0);
            int l2 = f(root->left, 1);
            int r2 = f(root->right, 1);
            return mp[{root,z}] = max(l2+r2,root->val+l+r);
        }
    }

    int rob(TreeNode* root) {
        return max(f(root,0),f(root,1));
    }
};
