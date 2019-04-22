#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>

#include "iterator_inorder.hpp"
#include "iterator_postorder.hpp"
#include "iterator_preorder.hpp"

template<typename T, class Iterator = InOrderIterator<Node<T>>>
class BST
{
    private:
        std::shared_ptr<Node<T>> _root;

    public:
        BST<T, Iterator>() {
            _root = nullptr;
        }

        BST<T, Iterator>(std::initializer_list<T> iv){
            for (auto value: iv)
                insert(value);                
        }

        BST<T, Iterator>(T key) {
            _root = std::make_shared<Node<T>>(Node<T>(key));
        }

        void insert(T key);
        void preorder(std::shared_ptr<Node<T>> next = nullptr, bool is_init = true);
        void postorder(std::shared_ptr<Node<T>> next = nullptr, bool is_init = true);
        void inorder(std::shared_ptr<Node<T>> next = nullptr, bool is_init = true);

        std::shared_ptr<Node<T>> search(T key);
        std::shared_ptr<Node<T>> search(T key, std::shared_ptr<Node<T>> next);

        using iterator = Iterator;

        Iterator begin() const {
            return Iterator(_root)++;
        }
        Iterator end() const {
            return Iterator(nullptr);
        }
};

#endif



