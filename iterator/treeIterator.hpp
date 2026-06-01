#pragma once

#include "common.hpp"
#include "treeNode.hpp"

class TreeIterator {
    protected:
        TreeNode* root;
    public:
        TreeIterator(TreeNode* root);
        virtual TreeNode* getNext() = 0;
        virtual bool hasNext() = 0;
};