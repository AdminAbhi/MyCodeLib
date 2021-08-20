// https://leetcode.com/problems/balanced-binary-tree/submissions/

// Time  - O(n * logn)
// Sapce - O(H)

int height(TreeNode* root, int d){
        if(root == nullptr) return d;
        return max(height(root->left, d+1), height(root->right, d+1));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int l = height(root->left, 1);
        int r = height(root->right, 1);
        if(abs(l-r) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
    
    
// Time  - O(n)
// Sapce - O(H)

int check(TreeNode* root, int d){
        if(root == nullptr) return d;
        int l = check(root->left, d+1);
        int r = check(root->right, d+1);
        if(l < 0 || r < 0) return -1;
        if(abs(l-r) > 1) return -1;
        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        if(check(root, 0) < 0) return false;
        return true;
    }
