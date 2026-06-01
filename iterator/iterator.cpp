#include "treeNode.hpp"
#include "dfsIterator.hpp"

int main() {
    TreeNode* root3 = new TreeNode(nullptr, nullptr, 4);
    TreeNode* root4 = new TreeNode(nullptr, nullptr, 5);
    TreeNode* root1 = new TreeNode(nullptr, root3, 3);
    TreeNode* root2 = new TreeNode(root4, nullptr, 2);
    TreeNode* root = new TreeNode(root1, root2, 1);
    DFSIterator* dfsIterator = root->getDFSIterator();
    while (dfsIterator->hasNext()) {
        cout << dfsIterator->getNext()->getVal() << " ";
    }
    return 0;
}