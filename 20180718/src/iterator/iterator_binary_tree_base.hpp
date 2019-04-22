#ifndef ITERATOR_BINARY_TREE_BASE_HPP
#define ITERATOR_BINARY_TREE_BASE_HPP

#include <memory>
#include <iterator>
#include "node.hpp"

template<class NodeT = Node<int>>
class IteratorBinaryTreeBase  /* : public std::iterator<std::forward_iterator_tag, int, NodeT, NodeT*, NodeT&> */ // Deprecating in C++17
{
    protected:
        std::shared_ptr<NodeT> _current;
        std::shared_ptr<NodeT> _root;
        bool first;

    public:
        // To use STL features, as a forward iterator

        using iterator_category = std::forward_iterator_tag;
        using value_type = NodeT;
        using difference_type = int;
        using pointer = NodeT*;
        using reference = NodeT&;

        IteratorBinaryTreeBase() = default;
        IteratorBinaryTreeBase(const std::shared_ptr<NodeT>& root) {
            _current = root;
            _root = root;
            first = true;
        }

        NodeT* operator*() const {
            if (_current != nullptr)
                return _current.get();

            return nullptr;        
        }

        NodeT* operator->(){
            return *(*this);
        }

        IteratorBinaryTreeBase& operator=(const IteratorBinaryTreeBase & other){
            if (this == &other)
                return *this;
            _current = other._current;
            _root = other._root;
            first = other.first;
            return *this;
        }

        bool operator==(const IteratorBinaryTreeBase& p) {
            return p._current == this->_current;

        }

        bool operator!=(const IteratorBinaryTreeBase& p) {
            return !(*this == p);
        }
};

#endif


