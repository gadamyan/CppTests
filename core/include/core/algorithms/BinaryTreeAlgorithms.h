//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <queue>
#include <stack>
#include <memory>
#include <vector>

namespace cpptests::core::algorithms {

template <typename T>
struct TreeNode {
    T data;
    std::shared_ptr<TreeNode<T>> right;
    std::shared_ptr<TreeNode<T>> left;
};

template <typename T>
std::shared_ptr<TreeNode<T>> insertTreeNode(const std::vector<T>& array, int begin, int end) {
    std::shared_ptr<TreeNode<T>> node;
    if (begin != end) {
        const int middle = (begin + end) / 2;
        node = std::make_shared<TreeNode<T>>();
        node->data = array[middle];
        node->left = insertTreeNode(array, begin, middle);
        node->right = insertTreeNode(array, middle + 1, end);
    }
    return node;
}

template <typename T>
std::shared_ptr<TreeNode<T>> createTreeFromVector(const std::vector<T>& array) {
    return insertTreeNode(array, 0, array.size());
}

template <typename T>
void insertIntoVector(std::shared_ptr<TreeNode<T>> node, std::vector<T>& array) {
    if (node) {
        insertIntoVector(node->left, array);
        array.push_back(node->data);
        insertIntoVector(node->right, array);
    }
}

template <typename T>
std::vector<T> createVectorFromTree(std::shared_ptr<TreeNode<T>> root) {
    std::vector<T> array;
    insertIntoVector(root, array);
    return array;
}

template <typename T>
std::vector<T> breadthFirstSearch(const std::shared_ptr<TreeNode<T>> root) {
    std::vector<T> result;
    if (!root) {
        return result;
    }
    std::queue<const std::shared_ptr<TreeNode<T>>> dataQueue;

    dataQueue.push(root);
    while (!dataQueue.empty()) {
        auto current = dataQueue.front();
        dataQueue.pop();
        if (current->left) {
            dataQueue.push(current->left);
        }
        if (current->right) {
            dataQueue.push(current->right);
        }
        result.push_back(current->data);
    }
    return result;
}
template <typename T>
std::vector<T> depthFirstSearch(const std::shared_ptr<TreeNode<T>> root) {
    std::vector<T> result;
    if (!root) {
        return result;
    }
    std::stack<const std::shared_ptr<TreeNode<T>>> dataStack;
    dataStack.push(root);
    while (!dataStack.empty()) {
        auto current = dataStack.top();
        dataStack.pop();
        if (current->right) {
            dataStack.push(current->right);
        }
        if (current->left) {
            dataStack.push(current->left);
        }
        result.push_back(current->data);
    }
    return result;
}

template <typename T>
std::shared_ptr<TreeNode<T>> reverseBinaryTree(std::shared_ptr<TreeNode<T>> root) {
    if (root) {
        std::swap(root->left, root->right);
        reverseBinaryTree(root->left);
        reverseBinaryTree(root->right);
    }
    return root;
}

}
