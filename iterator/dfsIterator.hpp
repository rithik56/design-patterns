#pragma once

#include "common.hpp"
#include "treeIterator.hpp"

class TreeNode;

class DFSIterator : public TreeIterator {
    private:
        stack<TreeNode*> st;
    public:
        DFSIterator(TreeNode* root);
        TreeNode* getNext() override;
        bool hasNext() override;
};