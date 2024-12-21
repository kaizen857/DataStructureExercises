#include "../includes/bintree.hpp"

inline void clear()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

int main(void)
{
    BinTree<char> tree;
    bool quit = false;
    char input;
    std::cout << "please input the bintree in Level order traversal (q to quit):" << "\n";
    // std::string input;
    while (!quit)
    {
        std::cin >> input;
        if (input == 'q' || input == 'Q')
        {
            quit = true;
        }
        else
        {
            // auto num = std::stoi(input);
            tree.insert(tree.getRoot(), input);
        }
    }
    bool isQuit = false;
    while (true)
    {
        if (isQuit)
        {
            break;
        }
        std::cout << "Please input the operation you want to perform:" << "\n";
        std::cout << "1. Insert a node" << "\n";
        std::cout << "2. Delete a node" << "\n";
        std::cout << "3. Print the tree" << "\n";
        std::cout << "4. Quit" << "\n";
        int input;
        std::cin >> input;
        clear();
        if (input == 1)
        {
            char data;
            std::cout << "Please input the data of the node you want to insert:" << "\n";
            std::cin >> data;
            tree.insert(tree.getRoot(), data);
        }
        else if (input == 2)
        {
            char data;
            std::cout << "Please input the data of the node you want to delete:" << "\n";
            std::cin >> data;
            tree.remove(tree.getRoot(), data);
        }
        else if (input == 3)
        {
            std::cout << "please input the bintree in Level order traversal:" << "\n";
            int choice;
            std::cout << "1. Preorder" << "\n";
            std::cout << "2. Inorder" << "\n";
            std::cout << "3. Postorder" << "\n";
            std::cout << "4. Levelorder" << "\n";
            std::cin >> choice;
            if (choice == 1)
            {
                tree.preorder(tree.getRoot());
            }
            else if (choice == 2)
            {
                tree.inorder(tree.getRoot());
            }
            else if (choice == 3)
            {
                tree.postorder(tree.getRoot());
            }
            else if (choice == 4)
            {
                tree.levelorder(tree.getRoot());
            }
            else
            {
                std::cout << "Invalid input, please try again." << "\n";
            }
            std::cout << "\n\n";
        }
        else if (input == 4)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input, please try again." << "\n";
        }

#ifdef __linux__
        system("read -n 1 -s -p \"Press any key to continue...\"");
        /*std::cin.ignore();
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.get();*/
#elif _WIN32
        system("pause");
#endif
        clear();
    }
    /*std::cout << "Preorder traversal:\n";
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
    tree.print();*/
    return 0;
}
