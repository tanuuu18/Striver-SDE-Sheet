// void pre(Node *node,vector<int>&v){
//     if(node==NULL) return ;
//     v.push_back(node->data);
//     pre(node->left,v);
//     pre(node->right,v);
// }
// vector <int> preorder(Node* root)
{
  // Your code here
//   vector<int>v;
//   pre(root,v);
//   return v;
   //Iterative Pre Order Traversal
  vector<int>pre;
  if(root==NULL){
      return pre;
  }
  stack<Node*>st;
  st.push(root);
  while(!st.empty()){
      Node* node = st.top();
      st.pop();
      pre.push_back(node->data);
      if(node->right){
          st.push(node->right);
      }
      if(node->left){
          st.push(node->left);
      }
  }
  return pre;
}
