// void solve(TreeNode*root,vector<int>&res){
//     if(root==NULL)
//         return;
    
//     solve(root->left,res);
//     solve(root->right,res);
//     res.push_back(root->data);
// }
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.

    //Recursive approach
    // vector<int>res;
    // solve(root,res);
    // return res;


    //<<<<<<<<<<<<---- Iterative Approach  (Using 2 stacks) ------->>>>>>>>>>>>>>
    vector<int>post;
    if(root==NULL){
        return post;
    }
    stack<TreeNode*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root= s1.top();
        s1.pop();
        s2.push(root);
        if(root->left){
            s1.push(root->left);
        }
        if(root->right){
            s1.push(root->right);
        }
    }
    while(!s2.empty()){
        post.push_back(s2.top()->data);
        s2.pop();
    }
    return post;
}
