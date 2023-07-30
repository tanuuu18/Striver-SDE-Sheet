int maxPath(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int leftPathSum = max(0,maxPath(root->left,maxi));
        int rightPathSum = max(0,maxPath(root->right,maxi));
        maxi = max(maxi,leftPathSum + rightPathSum + root->val);
        return root->val + max(leftPathSum,rightPathSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }
