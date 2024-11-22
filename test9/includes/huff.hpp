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
    };
    const std::shared_ptr<Node> getRoot() const
    {
        return root;
    }
    HuffmanTree(std::vector<std::shared_ptr<Node>> nodes);
    ~HuffmanTree() { root.reset(); }
    void printTree(std::shared_ptr<Node> node, std::string code = ""); // Helper function to print the tree

private:
    std::shared_ptr<Node> root;
    std::shared_ptr<Node> buildTree(std::vector<std::shared_ptr<Node>> nodes);
};

#endif