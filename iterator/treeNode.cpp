#include "treeNode.hpp"
#include "dfsIterator.hpp"

TreeNode::TreeNode(TreeNode *left, TreeNode *right, int val)
{
    this->left = left;
    this->right = right;
    this->val = val;
}

DFSIterator* TreeNode::getDFSIterator() {
    return new DFSIterator(this);
}

TreeNode *TreeNode::getLeft()
{
    return this->left;
}
TreeNode *TreeNode::getRight()
{
    return this->right;
}
int TreeNode::getVal()
{
    return this->val;
}