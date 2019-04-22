#include <iostream>
#include "bst.hpp"

template<typename T, class Iterator>
void BST<T, Iterator>::insert(T key)
{
    if (_root != nullptr)
    {
        std::shared_ptr<Node<T>> actual = _root;
        bool inserted = false;
        while (!inserted)
        {
            if (key <= actual.get()->data)
            {
                if (actual->left == nullptr)
                {
                    actual->left = std::make_shared<Node<T>>( Node<T>(key) );
                    inserted = true;
                }
                else
                    actual = actual->left;
            }
            else if (key > actual.get()->data)
            {
                if (actual->right == nullptr)
                {
                    actual->right = std::make_shared<Node<T>>( Node<T>(key) );
                    inserted = true;
                }
                else
                    actual = actual->right;
            }
        }
    }
    else
        _root = std::make_shared<Node<T>>( Node<T>(key) );
}

template<typename T, class Iterator>
void BST<T, Iterator>::preorder(std::shared_ptr<Node<T>> next, bool is_init)
{
    if (is_init)
        next = _root;
    if (next != nullptr)
    {
        std::cout << next->data << std::endl;
        preorder(next->left, false);
        preorder(next->right, false);
    }
}


template<typename T, class Iterator>
void BST<T, Iterator>::inorder(std::shared_ptr<Node<T>> next, bool is_init)
{
    if (is_init)
        next = _root;
    if (next!=nullptr)
    {
        inorder(next->left, false);
        std::cout << next->data << std::endl;
        inorder(next->right, false);
    }
}


template<typename T, class Iterator>
void BST<T, Iterator>::postorder(std::shared_ptr<Node<T>> next, bool is_init)
{
    if (is_init)
        next = _root;
    if (next!=nullptr)
    {
        postorder(next->left, false);
        postorder(next->right, false);
        std::cout << next->data << std::endl;            
    }
}

template<typename T, class Iterator>
std::shared_ptr<Node<T>> BST<T, Iterator>::search(T key)
{
    return search(key, _root);
}


template<typename T, class Iterator>
std::shared_ptr<Node<T>> BST<T, Iterator>::search(T key, std::shared_ptr<Node<T>> next)
{
    if (next == nullptr || key == next.get()->data)
        return next;
    if (key < next.get()->data)
        return search(key, next->left);
    else
        return search(key, next->right);
}
