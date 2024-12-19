#ifndef __HUFF_HPP__
#define __HUFF_HPP__

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>

// 节点结构体
struct Node
{
    char ch;        // 字符
    long long freq; // 字符频率
    Node *left;     // 左子树
    Node *right;    // 右子树

    Node(char character, long long frequency)
    {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

class HuffmanTree
{
private:
    Node *root;
    // 字符及其编码的映射
    std::map<char, std::string> codes;

    // 递归构建编码
    void generateCodes(Node *node, const std::string &currentCode)
    {
        if (!node)
        {
            return;
        }
        if (node->left == nullptr && node->right == nullptr)
        { // 叶子节点
            codes[node->ch] = currentCode;
        }
        generateCodes(node->left, currentCode + "0");  // 左边为0
        generateCodes(node->right, currentCode + "1"); // 右边为1
    }

public:
    // 构造函数，接受字符和频率的映射
    HuffmanTree(std::map<char, long long> &charFreq)
    {
        std::priority_queue<Node *, std::vector<Node *>, Compare> minHeap;

        // 将字符及频率插入优先队列
        for (auto &pair : charFreq)
        {
            minHeap.push(new Node(pair.first, pair.second));
        }

        // 构建哈夫曼树
        while (minHeap.size() > 1)
        {
            Node *left = minHeap.top();
            minHeap.pop();
            Node *right = minHeap.top();
            minHeap.pop();

            Node *merged = new Node('$', left->freq + right->freq); // 创建合并节点
            merged->left = left;
            merged->right = right;

            minHeap.push(merged); // 将新节点插入优先队列
        }

        root = minHeap.top();    // 获取根节点
        generateCodes(root, ""); // 生成编码
    }

    // 显示所有字符的编码
    void show()
    {
        for (auto &pair : codes)
        {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }

    std::string encode(const std::string &text)
    {
        std::string encodedText;
        for (char c : text)
        {
            encodedText += codes[c];
        }
        return encodedText;
    }

    std::string decode(const std::string &encodedText)
    {
        Node *node = root;
        std::string decodedText;
        for (char c : encodedText)
        {
            if (c == '0')
            {
                node = node->left;
            }
            else if (c == '1')
            {
                node = node->right;
            }
            if (node->left == nullptr && node->right == nullptr)
            {
                decodedText += node->ch;
                node = root;
            }
        }
        return decodedText;
    }

    // 析构函数，释放内存
    ~HuffmanTree()
    {
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            delete node;
        }
    }
};

#endif