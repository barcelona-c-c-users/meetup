#ifndef _ITERATOR_PREORDER_HPP
#define _ITERATOR_PREORDER_HPP

#include <stack>
#include <memory>
#include "node.hpp"

#include "iterator_binary_tree_base.hpp"

template<class NodeT = Node<int>>
class PreOrderIterator : public IteratorBinaryTreeBase<NodeT>
{
    private:
        std::stack<std::shared_ptr<NodeT>> stk;

    public:
        PreOrderIterator() = default;

        PreOrderIterator(const std::shared_ptr<NodeT>& root) : IteratorBinaryTreeBase<NodeT>(root) {

        }

        PreOrderIterator operator++(int n) {
            if (this->first)
            {
                this->first = false;                    
                if (this->_current != nullptr)
                    stk.push(this->_current);
            }

            if (!stk.empty())
            {
                this->_current = stk.top();
                stk.pop();
                if (this->_current->right != nullptr)
                    stk.push(this->_current->right);

                if (this->_current->left != nullptr)
                    stk.push(this->_current->left);

                return *this;              
            }    

            this->_current = nullptr;
            return *this;
        }

        PreOrderIterator operator++(){
            return this->operator++(0);
        }
};

#endif
