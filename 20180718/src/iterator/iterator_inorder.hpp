#ifndef _ITERATOR_INORDER_HPP
#define _ITERATOR_INORDER_HPP

#include <stack>
#include <memory>
#include "node.hpp"

#include "iterator_binary_tree_base.hpp"

template<typename NodeT = Node<int>>
class InOrderIterator : public IteratorBinaryTreeBase<NodeT>
{
    private:
        std::stack<std::shared_ptr<NodeT>> stk;

    public:
        InOrderIterator() = default;

        InOrderIterator(const std::shared_ptr<NodeT>& root) : IteratorBinaryTreeBase<NodeT>(root) {

        }

        InOrderIterator operator++(int n) {
            if (!this->first)
                this->_current = this->_current->right;
            else
                this->first = false;

            while (this->_current != nullptr )
            {
                stk.push(this->_current);
                this->_current = this->_current->left;
            } 

            if ( !stk.empty() ){
                this->_current = stk.top();
                stk.pop();
                return *this;                    
            }

            return InOrderIterator(std::shared_ptr<NodeT>(nullptr));
        }

        InOrderIterator operator++(){
            return this->operator++(0);
        }
};

#endif
