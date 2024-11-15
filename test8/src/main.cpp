#include "../includes/bintree.hpp"
#include <string>

int main(void)
{
    BinTree<int> tree;
    bool quit = false;
    std::string input;
    while (!quit)
    {
        std::cin >> input;
        if (input == "q")
        {
            quit = true;
        }
        else
        {
            auto num = std::stoi(input);
            tree.insert(num);
        }
    }

    tree.show();
    std::cout << "\n\n\n\n";
    tree.levelorder();
    return 0;
}