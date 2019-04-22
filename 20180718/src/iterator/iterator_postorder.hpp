#ifndef ITERATOR_POSTORDER_HPP
#define ITERATOR_POSTORDER_HPP

#include <stack>
#include <memory>
#include "node.hpp"

#include "iterator_binary_tree_base.hpp"

template<typename NodeT = Node<int>>
class PostOrderIterator : public IteratorBinaryTreeBase<NodeT>
{
    private:
        std::stack<std::shared_ptr<NodeT>> stk;
        std::stack<std::shared_ptr<NodeT>> stk2;

    public:
        PostOrderIterator() = default;

        PostOrderIterator(const std::shared_ptr<NodeT>& root) : IteratorBinaryTreeBase<NodeT>(root) {

        }

        PostOrderIterator operator++(int n) {
            if (this->_current != nullptr && this->first)
                stk.push(this->_current);

            while (!stk.empty() && this->first)
            {
                this->_current = stk.top();
                stk.pop();

                stk2.push( this->_current );
                if ( this->_current->left != nullptr )
                    stk.push(this->_current->left);
                if (this->_current->right != nullptr)
                    stk.push(this->_current->right);
            }                
            this->first = false;

            if (!stk2.empty()) 
            {
                this->_current = stk2.top();
                stk2.pop();
            }
            else 
                this->_current = nullptr;

            return *this;
        }

        PostOrderIterator operator++(){
            return this->operator++(0);
        }
};

#endif

