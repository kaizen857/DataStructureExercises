#ifndef BINTREE_HPP
#define BINTREE_HPP
#include <queue>
#include <iostream>

template <typename T>
class BinTree
{
public:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        Node *parent;
        Node(T data) :
            data(data), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    BinTree() :
        root(nullptr) {}

    // 析构函数
    ~BinTree()
    {
        clear(root);
    }

    // 清空二叉树
    void clear(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }

    // 前序遍历
    void preorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // 中序遍历
    void inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    // 后序遍历
    void postorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    // 层序遍历
    void levelorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        std::queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            std::cout << cur->data << " ";
            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
    }

    // 寻找最小值
    Node *findMin(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    // 寻找最大值
    Node *findMax(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    // 寻找某个值
    Node *find(Node *node, T value)
    {
        if (node == nullptr || node->data == value)
        {
            return node;
        }
        if (value < node->data)
        {
            return find(node->left, value);
        }
        else
        {
            return find(node->right, value);
        }
    }

    // 插入节点
    void insert(Node *node, T value)
    {
        if (node == nullptr)
        {
            root = new Node(value);
            return;
        }
        if (value < node->data)
        {
            if (node->left == nullptr)
            {
                node->left = new Node(value);
                node->left->parent = node;
            }
            else
            {
                insert(node->left, value);
            }
        }
        else
        {
            if (node->right == nullptr)
            {
                node->right = new Node(value);
                node->right->parent = node;
            }
            else
            {
                insert(node->right, value);
            }
        }
    }

    // 删除节点
    void remove(Node *node, T value)
    {
        if (node == nullptr)
        {
            return;
        }
        if (value < node->data)
        {
            remove(node->left, value);
        }
        else if (value > node->data)
        {
            remove(node->right, value);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                if (node->parent->left == node)
                {
                    node->parent->left = nullptr;
                }
                else
                {
                    node->parent->right = nullptr;
                }
                delete node;
            }
            else if (node->left == nullptr)
            {
                if (node->parent->left == node)
                {
                    node->parent->left = node->right;
                    node->right->parent = node->parent;
                }
                else
                {
                    node->parent->right = node->right;
                    node->right->parent = node->parent;
                }
                delete node;
            }
            else if (node->right == nullptr)
            {
                if (node->parent->left == node)
                {
                    node->parent->left = node->left;
                    node->left->parent = node->parent;
                }
                else
                {
                    node->parent->right = node->left;
                    node->left->parent = node->parent;
                }
                delete node;
            }
            else
            {
                Node *minNode = findMin(node->right);
                node->data = minNode->data;
                remove(node->right, minNode->data);
            }
        }
    }
    auto getRoot() const { return root; }

    // 凹入法打印
    void print()
    {
        int height = getHeight(root);
        int width = (1 << height) - 1;                                                              // 整棵树的宽度
        std::vector<std::vector<std::string>> output(height, std::vector<std::string>(width, " ")); // 初始化输出矩阵

        fillOutput(output, root, 0, 0, width - 1); // 从根节点开始填充输出

        for (const auto &row : output) // 输出每一行
        {
            for (const auto &str : row)
            {
                std::cout << str; // 输出节点的字符串
            }
            std::cout << std::endl; // 换行
        }
    }

private:
    Node *root;
    // 获取树的高度
    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    // 填充输出矩阵
    // 填充输出矩阵
    void fillOutput(std::vector<std::vector<std::string>> &output, Node *node, int level, int posStart, int posEnd)
    {
        if (node == nullptr)
        {
            return;
        }

        int mid = posStart + (posEnd - posStart) / 2;    // 找到当前节点应该放置的中间位置
        output[level][mid] = std::string(1, node->data); // 填入当前节点

        // 递归填充左右子树
        fillOutput(output, node->left, level + 1, posStart, mid - 1);
        fillOutput(output, node->right, level + 1, mid + 1, posEnd);
    }
};

#endif