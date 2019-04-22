#include <iostream>
#include "bst.cc"

int main(void)
{
    BST<int> binary = {5, 3, 2, 5, 7, 8};
    std::cout << "USING FUNCTIONS/RECURSION" << std::endl;
    std::cout << "PREORDER" << std::endl;
    binary.preorder();

    std::cout << "INORDER INT" << std::endl;
    binary.inorder();

    std::cout << "POSTORDEN" << std::endl;
    binary.postorder();

    BST<char, InOrderIterator<Node<char>>> chr_binary = { 'd', 'z', 'f', 'v', 'a', 'b', 'y' };
    BST<int, PreOrderIterator<Node<int>>> preBinary = { 5, 3, 2, 5, 7, 8 };
    BST<int, PostOrderIterator<Node<int>>> postBinary = { 5, 3, 2, 5, 7, 8 };    

    std::cout << "USING ITERATORS" << std::endl;    
    BST<int>::iterator it_Inorder;
    BST<int, PreOrderIterator<Node<int>> >::iterator it_Preorder = preBinary.begin();
    auto it_PostOrder = postBinary.begin();        

    std::cout << "PREORDER" << std::endl;
    for(auto node: preBinary)
        std::cout << node->data << std::endl;
    
    std::cout << "INORDER INT" << std::endl;
    for (it_Inorder = binary.begin(); it_Inorder != binary.end(); it_Inorder++ )
        std::cout << it_Inorder->data << std::endl;

    std::cout << "INORDER CHAR" << std::endl;
    for (auto node: chr_binary)
        std::cout << node->data << std::endl;        

    std::cout << "POSTORDER" << std::endl;
    for (auto node: postBinary)
        std::cout << node->data << std::endl;

    std::cout << "USING ADVANCE ON INORDER" << std::endl;
    auto it = binary.begin();
    int i = 2; // mmmmh, it should be one but... ?
    while (it != binary.end()){
        std::cout << (*it)->data << std::endl;
        std::advance(it, i);
    }

    it = binary.begin();
    std::cout << "USING NEXT" << std::endl;
    std::cout << it->data << std::endl;
    it = std::next(it, 2);
    std::cout << it->data << std::endl;
    it = std::next(it, 2);
    std::cout << it->data << std::endl;

    std::copy(binary.begin(), binary.end(), std::ostream_iterator<Node<int>*>(std::cout, "\n"));
    std::for_each( binary.begin(), binary.end(), []( Node<int>* node) { std::cout << "Using Foreach: " << node->data << std::endl; } );

    return 0;
}

