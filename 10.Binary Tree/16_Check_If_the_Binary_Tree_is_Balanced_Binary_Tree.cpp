//  int findHeight(TreeNode* root) {
//         if(root==NULL){
//             return 0;
//         }
//         queue<TreeNode*>q;
//         int level=0;
//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                 auto it = q.front();
//                 q.pop();
//                 if(it->left){
//                     q.push(it->left);
//                 }
//                 if(it->right){
//                     q.push(it->right);
//                 }
//             }
//             level++;
//         }
//         return level;
//     }

    int dfsHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh = dfsHeight(root->left);
        if(lh==-1){
            return -1;
        }
        int rh = dfsHeight(root->right);
        if(rh==-1){
            return -1;
        }
        if(abs(lh-rh)>1){
            return -1;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {

        // <------------ Naive Approach --------------->
        // if(root==NULL){
        //     return true;
        // }
        // int lh = findHeight(root->left);
        // int rh = findHeight(root->right);
        // if(abs(lh-rh)>1){
        //     return false;
        // }
        // bool left = isBalanced(root->left);
        // bool right = isBalanced(root->right);

        // if(!left || !right){
        //     return false;
        // }
        // return true;

        //<----------- Post order Traversal approach ---------------->
        return dfsHeight(root)!=-1;
    }
