 int maxDepth(TreeNode* root) {

        //<----------- Using Recursion ----------->
        // if(!root)
        //     return 0;  // return 0 for null node
        // int ldepth = maxDepth(root->left);
        // int rdepth = maxDepth(root->right);
        // return max(ldepth,rdepth)+1; // return depth of the subtree rooted at root



        //<------------- Using Level Order Traversal ---------------->
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        int level=0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            level++;
        }
        return level;

    }
