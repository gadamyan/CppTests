//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <vector>

namespace cpptests::core::algorithms {

template <typename T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;
};

template <typename T>
std::shared_ptr<ListNode<T>> createLinkedList(const std::vector<T>& array) {
    std::shared_ptr<ListNode<T>> root;
    std::shared_ptr<ListNode<T>> current;
    for (const auto& item : array) {
        auto temp = std::make_shared<ListNode<T>>();
        temp->data = item;
        if (root) {
            current->next = temp;
            current = temp;
        } else {
            root = temp;
            current = temp;
        }
    }
    return root;
}

template <typename T>
std::vector<T> createVectorFromLinkedList(std::shared_ptr<ListNode<T>> root) {
    std::vector<T> result;
    while (root) {
        result.push_back(root->data);
        root = root->next;
    }
    return result;
}

template <typename T>
std::shared_ptr<ListNode<T>> reverseLinkedList(std::shared_ptr<ListNode<T>> root) {
    std::shared_ptr<ListNode<T>> prev = nullptr;
    std::shared_ptr<ListNode<T>> current = std::move(root);
    while (current != nullptr) {
        auto next = std::move(current->next);
        current->next = std::move(prev);
        prev = std::move(current);
        current = std::move(next);
    }
    return prev;
}

}
