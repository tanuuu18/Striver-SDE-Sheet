 vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int>ans;
      if(node==NULL){
          return ans;
      }
      queue<Node*>q;
      q.push(node);
      while(!q.empty()){
          int size = q.size();
          for(int i=0;i<size;i++){
              Node* temp = q.front();
              q.pop();
              if(temp->left){
                  q.push(temp->left);
              }
              if(temp->right){
                  q.push(temp->right);
              }
              ans.push_back(temp->data);
          }
      }
      return ans;
    }
