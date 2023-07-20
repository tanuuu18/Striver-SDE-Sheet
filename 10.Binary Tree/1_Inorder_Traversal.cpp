vector<int> inorderTraversal(TreeNode* root) {
      
    // <------------- Iterative Approach -------------------->

    // Intuition: In inorder traversal, the tree is traversed in this way:
    //            root, left, right.
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

    stack<TreeNode *>st;
    TreeNode *node = root;
    vector<int>in;
    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()){
                break;
            }
            node = st.top();
            st.pop();
            in.push_back(node->val);
            node = node->right;
            }
        }
    return in;     

}