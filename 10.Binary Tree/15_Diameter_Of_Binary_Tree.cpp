 //<------------- Brute Force Approach --------------->
    // int ans = 0;
    // int findHeight(TreeNode* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int lh = findHeight(root->left);
    //     int rh = findHeight(root->right);
    //     // ans = max(ans,lh+rh);
    //     return 1+max(lh,rh);
    // }

    //<------------- Efficient Approach (Using Postorder Traversal) --------------->
    int height(TreeNode* root, int &dia){
        if(root==NULL){
            return 0;
        }
        int lh = height(root->left,dia);
        int rh = height(root->right,dia);
        dia = max(dia,lh+rh);
        return 1+ max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        //<------------- Brute Force Approach --------------->
        // if(root==NULL){
        //     return 0;
        // }
        // int lh = findHeight(root->left);
        // int rh = findHeight(root->right);
        // ans = max(ans,lh+rh);
        // diameterOfBinaryTree(root->left);
        // diameterOfBinaryTree(root->right);
        // return ans;

        //<------------- Efficient Approach (Using Postorder Traversal) --------------->
        int dia = 0;
        height(root,dia);
        return dia;
    }
