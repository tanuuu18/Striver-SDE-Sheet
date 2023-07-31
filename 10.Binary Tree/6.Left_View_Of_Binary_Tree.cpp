void recursion(Node* root,int level,vector<int>&res){
    if(root==NULL){
        return ;
    }
    if(res.size()==level){
        res.push_back(root->data);
    }

  //For right view , first right then left
    recursion(root->left,level+1,res);
    recursion(root->right,level+1,res);

}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>res;
   recursion(root,0,res);
   return res;
}
