#include "../includes/bintree.hpp"
#include <string>

int main(void)
{
    BinTree<char> tree;
    bool quit = false;
    char input;
    std::cout << "please input the bintree in Level order traversal:" << "\n";
    // std::string input;
    while (!quit)
    {
        std::cin >> input;
        if (input == 'q')
        {
            quit = true;
        }
        else
        {
            // auto num = std::stoi(input);
            tree.insert(tree.getRoot(), input);
        }
    }
    std::cout << "Preorder traversal:\n";
    tree.preorder(tree.getRoot());
    std::cout << "\n\n";
    std::cout << "Inorder traversal:\n";
    tree.inorder(tree.getRoot());
    std::cout << "\n\n";
    std::cout << "Postorder traversal:\n";
    tree.postorder(tree.getRoot());
    std::cout << "\n\n";
    std::cout << "Level order traversal:\n";
    tree.levelorder(tree.getRoot());
    std::cout << "\n\n\n\n";
    tree.print();
    return 0;
}
