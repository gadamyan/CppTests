//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <iostream>
#include <queue>
#include <memory>
#include <vector>

namespace cpptests::core::algorithms {

template <typename T>
struct TreeNode
{
    T data;
    std::shared_ptr<TreeNode<T>> right;
    std::shared_ptr<TreeNode<T>> left;
};

namespace
{

template <typename T>
std::shared_ptr<TreeNode<T>> insert_tree_node(const std::vector<T>& array, int begin, int end)
{
    std::shared_ptr<TreeNode<T>> node;
    if (begin != end)
    {
        const int middle = (begin + end) / 2;
        node = std::make_shared<TreeNode<T>>();
        node->data = array[middle];
        node->left = insert_tree_node(array, begin, middle);
        node->right = insert_tree_node(array, middle + 1, end);
    }
    return node;
}
}

template <typename T>
std::shared_ptr<TreeNode<T>> create_tree_from_vector(const std::vector<T>& array)
{
    return insert_tree_node(array, 0, array.size());
}

template <typename T>
void insert_into_vector(std::shared_ptr<TreeNode<T>> node, std::vector<T>& array)
{
    if (node)
    {
        insert_into_vector(node->left, array);
        array.push_back(node->data);
        insert_into_vector(node->right, array);
    }
}

template <typename T>
std::vector<T> create_vector_from_tree(std::shared_ptr<TreeNode<T>> root)
{
    std::vector<T> array;
    insert_into_vector(root, array);
    return array;
}


    template <typename T>
    static void printBTree(const std::shared_ptr<TreeNode<T>> root)
    {
        if (root) {
            return;
        }
        std::queue<const std::shared_ptr<TreeNode<T>>> dataQueue;

        dataQueue.push(root);
        while (!dataQueue.empty())
        {
            auto current = dataQueue.front();
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
std::shared_ptr<TreeNode<T>> reverse_binary_tree(std::shared_ptr<TreeNode<T>> root)
{
    if (root)
    {
        std::swap(root->left, root->right);
        reverse_binary_tree(root->left);
        reverse_binary_tree(root->right);
    }
    return root;
}

}
