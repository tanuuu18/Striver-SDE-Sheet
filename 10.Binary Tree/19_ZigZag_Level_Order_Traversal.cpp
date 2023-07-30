vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)
            return result;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);
            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                //Find position to fill node's value
                int index = leftToRight ? i : size-i-1;
                temp[index] = node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            //after this level
            leftToRight = !leftToRight;
            result.push_back(temp);
        }
        return result;
    }
