#include "dfsIterator.hpp"
#include "treeNode.hpp"

DFSIterator::DFSIterator(TreeNode* treeNode) : TreeIterator(treeNode) {
    st.push(this->root);
    TreeNode* temp = this->root;
    while (temp->getLeft()) {
        st.push(temp->getLeft());
        temp = temp->getLeft();
    }
}
        
TreeNode* DFSIterator::getNext() {
    TreeNode* ans = this->st.top();
    st.pop();
    if (ans->getRight()) {
        TreeNode* temp = ans->getRight();
        st.push(temp);
        if (temp->getLeft()) {
            while (temp->getLeft()) {
                st.push(temp->getLeft());
                temp = temp->getLeft();
            }
        }
    }
    return ans;
};
        
bool DFSIterator::hasNext() {
    return !st.empty();
};