
void inorder(TreeNode *node,vector<int>&in){
        if(node==NULL) 
            return;
        inorder(node->left,in);
        in.push_back(node->val);
        inorder(node->right,in);
    }


vector<int> inorderTraversal(TreeNode* root) {
      
    // <------------- Iterative Approach -------------------->

    // Intuition: In inorder traversal, the tree is traversed in this way:
    //            left,root, right.
    //            We first visit the left child,
    //            after returning from it we print the current node value,
    //            then we visit the right child. 
    //            The fundamental problem we face in this scenario is that 
    //            there is no way that we can move from a child to a parent.


    //            To solve this problem, we use an explicit stack data structure.
    //             While traversing we can insert node values to the stack in such a way 
    //             that we always get the next node value at the top of the stack.

    // Step 1: Take a stack data structure.
    // Step 2: Repeat these steps.
    //         i) Push the node in the stack until it's left child != NULL
    //         else 
    //         ii) if stack is not empty:
    //             a) pop the top value & print it.
    //             b) push it's right child.
    //         iii) if stack becomes empty & all nodes printed
    //              then break the loop;

       
        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N)                  |  //running a single loop
		// |  Space Complexity = O(N)                 |  
		// |__________________________________________|

    // stack<TreeNode *>st;
    // TreeNode *node = root;
    // vector<int>in;
    // while(true){
    //     if(node!=NULL){
    //         st.push(node);
    //         node = node->left;
    //     }
    //     else{
    //         if(st.empty()){
    //             break;
    //         }
    //         node = st.top();
    //         st.pop();
    //         in.push_back(node->val);
    //         node = node->right;
    //         }
    //     }
    // return in;     


    // <------------------ Recursive Approach ------------------>

    // Algorithm : In Inorder traversal, the tree is traversed in this way:
    //             left, root, right


    // Step 1: First visit the left child and go till we find a leaf node.
    // Step 2: then  print that node
    // Step 3: recursively visit the right child.
    // Step 4: if node == NULL 
    //         then return to it's parent.


        //  __________________________________________
        // |                                          |
        // |  Time Complexity = O(N)                  |  //running a single loop
		// |  Space Complexity = O(N)                 |  
		// |__________________________________________|

    vector<int>in;
    inorder(root,in);
    return in;
}