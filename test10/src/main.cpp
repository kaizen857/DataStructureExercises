#include "../includes/map.hpp"
#include <climits>

int main(void)
{
    std::cout << "请输入总节点数：";
    int size;
    std::cin >> size;
    std::vector<std::set<int>> m(size + 2);
    std::cout << "请输入边数：";
    int edge_num;
    std::cin >> edge_num;
    int minnum = INT_MAX;
    for (int i = 0; i < edge_num; i++)
    {
        int u, v;
        std::cin >> u >> v;
        m[u].insert(v);
        m[v].insert(u);
        minnum = std::min(minnum, std::min(u, v));
    }
    Map map(size, m);
    while (true)
    {
        std::cout << "1. bfs\n2. dfs\nq. 退出\n 请选择操作：";
        char choice;
        std::cin >> choice;
        if (choice == '1')
        {
            int start;
            std::cout << "请输入起始节点：";
            std::cin >> start;
            map.bfs(start);
        }
        else if (choice == '2')
        {
            int start;
            std::cout << "请输入起始节点：";
            std::cin >> start;
            map.dfs(start);
        }
        else
        {
            return 0;
        }
#ifdef _WIN32
        system("pause");
        system("cls");
#endif
#ifdef __linux__
        std::cin.ignore();
        std::cout << "请按任意键继续";
        std::cin.get();
        system("clear");
#endif
    }
    return 0;
}