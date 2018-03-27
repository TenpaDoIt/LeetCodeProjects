#include "../HeaderFiles/MaxDepthBinaryTree.hpp"


int MaxDepthBinaryTree::maxDepth(TreeNode* root)
{
    int TheMaxD = 0;
    return SearchDepth(root, TheMaxD);
}

int MaxDepthBinaryTree::SearchDepth(TreeNode* Tree, int MaxDep)
{
    int leftMax = 0, rightMax = 0;
    if (Tree == NULL)
        return MaxDep;
    leftMax = SearchDepth(Tree->left, MaxDep+1);
    rightMax = SearchDepth(Tree->right, MaxDep+1);
    return max(max(leftMax, rightMax), MaxDep);
}

void MaxDepthBinaryTree::Test()
{

}