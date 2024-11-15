#ifndef BINTREE_HPP
#define BINTREE_HPP

#include <queue>
#include <iostream>

// 二叉树模板类
template <typename T>
class BinTree
{
public:
    // 节点类
    class Node
    {
    public:
        T data;
        Node *left;
        Node *right;
        Node(T data) :
            data(data), left(nullptr), right(nullptr) {}
    };

    // 构造函数
    BinTree() :
        root(nullptr) {}
    // 使用前序方法建立二叉树
    BinTree(T *preorder, int size) :
        root(nullptr)
    {
        build(preorder, 0, size - 1, 1);
    }
    // 析构函数
    ~BinTree()
    {
        clear(root);
    }

    // 清空二叉树
    void clear()
    {
        clear(root);
        root = nullptr;
    }

    // 前序遍历
    void preorder() const
    {
        preorder(root);
    }

    // 中序遍历
    void inorder() const
    {
        inorder(root);
    }

    // 后序遍历
    void postorder() const
    {
        postorder(root);
    }

    // 层序遍历
    void levelorder() const
    {
        if (root == nullptr)
            return;
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            std::cout << node->data << " ";
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    // 插入节点
    void insert(T data)
    {
        root = insert(root, data);
    }

    // 删除节点
    void remove(T data)
    {
        root = remove(root, data);
    }

    // 按凹入法显示二叉树结构
    void show() const
    {
        show(root, 0);
    }

private:
    // 前序遍历
    void preorder(Node *node) const
    {
        if (node == nullptr)
            return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // 中序遍历
    void inorder(Node *node) const
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    // 后序遍历
    void postorder(Node *node) const
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    // 层序遍历
    void levelorder(Node *node) const
    {
        if (node == nullptr)
            return;
        std::queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            std::cout << node->data << " ";
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    // 插入节点
    Node *insert(Node *node, T data)
    {
        if (node == nullptr)
            return new Node(data);
        if (data < node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }

    // 删除节点
    Node *remove(Node *node, T data)
    {
        if (node == nullptr)
            return node;
        if (data < node->data)
            node->left = remove(node->left, data);
        else if (data > node->data)
            node->right = remove(node->right, data);
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // 清空二叉树
    void clear(Node *node)
    {
        if (node == nullptr)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    void build(T *preorder, int start, int end, int &preIndex)
    {
        if (start > end)
            return;
        root = new Node(preorder[preIndex++]);
        build(preorder, start, start + end - preIndex, preIndex);
        build(preorder, start + end - preIndex + 1, end, preIndex);
    }

    void show(Node *node, int depth) const
    {
        if (node == nullptr)
            return;
        show(node->right, depth + 1);
        for (int i = 0; i < depth; i++)
            std::cout << "  ";
        std::cout << node->data << std::endl;
        show(node->left, depth + 1);
    }

    Node *findMin(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node *findMax(Node *node)
    {
        Node *current = node;
        while (current->right != nullptr)
            current = current->right;
        return current;
    }

    Node *root;
};

#endif