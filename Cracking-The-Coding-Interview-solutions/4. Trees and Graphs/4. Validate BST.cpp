// https://leetcode.com/problems/validate-binary-search-tree

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
    long long maxi(long long a, long long b, long long c){
        //cout << "maxi = " << a <<" "<< b <<" "<< c << endl; 
        return a > b? (a > c? a: c) : (b > c? b : c);
    }
    long long mini(long long a, long long b, long long c){
        //cout << "mini = " << a <<" "<< b <<" "<< c << endl;
        return a < b? (a < c? a: c) : (b < c? b : c);
    }
    long long maxx(TreeNode *root){
        if(root == nullptr) return LONG_MIN;
        return maxi(maxx(root->left), root->val, maxx(root->right));
    }
    long long minn(TreeNode *root){
        if(root == nullptr) return LONG_MAX;
        return mini(minn(root->left), root->val, minn(root->right));
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        //cout << root->val << endl;
        long long l = maxx(root->left);  //cout << "l = " << l << endl;
        long long r = minn(root->right); //cout << "r = " << r << endl;
        if(l >= root->val || root->val >= r) return false;
        else return isValidBST(root->left) && isValidBST(root->right);
    }
};




