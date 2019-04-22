#ifndef NODE_HPP
#define NODE_HPP

template<typename T = int>
class Node
{
    public:
        Node<T>() {};
        T data;
        std::shared_ptr<Node<T>> left = nullptr;
        std::shared_ptr<Node<T>> right = nullptr;

        Node<T>(T x) : data(x) {};

        T operator--(int n){
            data--;
            return data;
        }
        T operator--(){
            --data;
            return data;
        }

        friend std::ostream& operator<<(std::ostream& s, const Node<T>* p){
            return s << "Calling from ostream: " << p->data;
        }
};

#endif
