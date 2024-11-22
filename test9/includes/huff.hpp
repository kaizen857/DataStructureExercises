#ifndef __HUFF_HPP__
#define __HUFF_HPP__

#include <memory>
#include <vector>
#include <string>
class HuffmanTree
{
public:
    class Node
    {
    private:
        char mdata;
        int mfrequency;
        std::shared_ptr<Node> mleft;
        std::shared_ptr<Node> mright;

    public:
        // 作为超节点
        Node(int frequency) :
            mdata('\0'), mfrequency(frequency), mleft(nullptr), mright(nullptr) {}
        Node(int frequency, std::shared_ptr<Node> left, std::shared_ptr<Node> right) :
            mdata('\0'), mfrequency(frequency), mleft(left), mright(right) {}
        // 作为叶子节点
        Node(char data, int frequency) :
            mdata(data), mfrequency(frequency), mleft(nullptr), mright(nullptr) {}
        Node(char data, int frequency, std::shared_ptr<Node> left, std::shared_ptr<Node> right) :
            mdata(data), mfrequency(frequency), mleft(left), mright(right) {}
        ~Node();
        char getData();
        int getFrequency();
        std::shared_ptr<Node> getLeft();
        std::shared_ptr<Node> getRight();
        void setLeft(std::shared_ptr<Node> left);
        void setRight(std::shared_ptr<Node> right);
        friend class HuffmanTree;
    };
    const std::shared_ptr<Node> getRoot() const
    {
        return root;
    }
    HuffmanTree(std::vector<std::shared_ptr<Node>> nodes);
    ~HuffmanTree() { root.reset(); }
    void printTree(std::shared_ptr<Node> node, std::string code = "");
    std::string encode(const std::string &text);
    std::string decode(const std::string &encodedText);

private:
    std::shared_ptr<Node> root;
    void clear()
    {
        root.reset();
    }
};

#endif