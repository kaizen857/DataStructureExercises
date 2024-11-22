#include "../includes/huff.hpp"
#include <algorithm>
HuffmanTree::HuffmanTree(std::vector<std::shared_ptr<Node>> nodes)
{
    // 构建哈夫曼树
    while (nodes.size() > 1)
    {
        // 按照节点的权重进行排序
        std::sort(nodes.begin(), nodes.end(), [](const std::shared_ptr<Node> &a, const std::shared_ptr<Node> &b)
                  { return a->mfrequency < b->mfrequency; });

        // 取出权重最小的两个节点
        std::shared_ptr<Node> left = nodes.front();
        nodes.erase(nodes.begin());
        std::shared_ptr<Node> right = nodes.front();
        nodes.erase(nodes.begin());

        // 创建一个新的节点，其权重为两个子节点权重之和
        std::shared_ptr<Node> parent = std::make_shared<Node>(left->mfrequency + right->mfrequency);
        parent->mleft = left;
        parent->mright = right;

        // 将新的节点加入到节点列表中
        nodes.push_back(parent);
    }

    // 最后一个节点即为哈夫曼树的根节点
    root = nodes.front();
}

// 对给定的文本进行编码
std::string HuffmanTree::encode(const std::string &text)
{
    
}
