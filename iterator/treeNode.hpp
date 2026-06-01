#pragma once

#include "common.hpp"

class DFSIterator;

class TreeNode {
    private:
        TreeNode* left;
        TreeNode* right;
        int val;
    public:
        TreeNode(TreeNode* left, TreeNode* right, int val);
        DFSIterator* getDFSIterator();
        TreeNode* getLeft();
        TreeNode* getRight();
        int getVal();
};