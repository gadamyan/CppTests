#ifndef ReverseBTree_h__
#define ReverseBTree_h__

#include <iostream>
#include <queue>


template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

class ReverseBTree
{
public:
    
    static TreeNode<int>* createBTree()
    {
        TreeNode<int>* node1 = new TreeNode<int> { 1, nullptr, nullptr };
        TreeNode<int>* node4 = new TreeNode<int> { 4, nullptr, nullptr };
        TreeNode<int>* node3 = new TreeNode<int> { 3, node1, node4 };
        
        
        TreeNode<int>* node9 = new TreeNode<int> { 9, nullptr, nullptr };
        TreeNode<int>* node6 = new TreeNode<int> { 6, nullptr, nullptr };
        TreeNode<int>* node8 = new TreeNode<int> { 8, nullptr, node9 };
        TreeNode<int>* node7 = new TreeNode<int> { 7, node6, node8 };
        
        TreeNode<int>* node5 = new TreeNode<int> { 5, node3, node7 };
        return node5;
    }
    
    static void removeBTree(TreeNode<int>* root)
    {
        if (root == nullptr)
        {
            return;
        }
        removeBTree(root->left);
        removeBTree(root->right);
        delete root;
    }
    
    static void testReverse()
    {
        TreeNode<int>* root = createBTree();
        reverse(root);
        removeBTree(root);
    }
    
    static void printBTree(const TreeNode<int>* root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::queue<const TreeNode<int>*> dataQueue;
        
        dataQueue.push(root);
        while (!dataQueue.empty())
        {
            const TreeNode<int>* current = dataQueue.front();
            dataQueue.pop();
            if (current->left != nullptr)
            {
                dataQueue.push(current->left);
            }
            if (current->right != nullptr)
            {
                dataQueue.push(current->right);
            }
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }
    
    template <typename T>
    static void reverse(TreeNode<T>* root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode<T>* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverse(root->left);
        reverse(root->right);
    }

};

#endif // ReverseBTree_h__