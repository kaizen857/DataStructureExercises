#include <bits/stdc++.h>

template <typename Elemtype>
class LinkedList
{
private:
    struct LNode
    {
        Elemtype data;
        LNode *next;
    };
    LNode *L;

public:
    LinkedList()
    {
        L = new LNode;
        L->next = nullptr;
    }

    ~LinkedList()
    {
        // 释放节点
        LNode *p = L;
        while (p)
        {
            LNode *temp = p;
            p = p->next;
            delete temp;
        }
    }

    bool InitList()
    {
        L->next = nullptr;
        return true;
    }

    bool GetElem(int i, Elemtype &e)
    {
        int j = 1;
        LNode *p = L->next;
        while (j < i && p)
        {
            p = p->next;
            j++;
        }
        if (!p || j > i)
        {
            return false;
        }
        e = p->data;
        return true;
    }

    LNode *LocateElem(Elemtype e)
    {
        LNode *p = L->next;
        while (p && p->data != e)
        {
            p = p->next;
        }
        return p;
    }

    bool Insert(int i, Elemtype &e)
    {
        int j = 0;
        LNode *p = L;
        while (p && j < i - 1)
        {
            p = p->next;
            j++;
        }
        if (!p || j > i - 1)
        {
            return false;
        }
        LNode *s = new LNode;
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }

    bool Delete(int i, Elemtype &e)
    {
        LNode *p = L;
        int j = 0;
        while (p->next && j < i - 1)
        {
            p = p->next;
            j++;
        }
        if (!(p->next) || j > i - 1)
        {
            return false;
        }
        LNode *q = p->next;
        p->next = q->next;
        e = q->data;
        delete q;
        return true;
    }

    void CreateListH(int n)
    {
        LNode *p;
        InitList(); // 确保初始化
        for (int i = 0; i < n; i++)
        {
            p = new LNode;
            std::cin >> p->data;
            p->next = L->next;
            L->next = p;
        }
    }

    void CreateListR(int n)
    {
        LNode *r, *p;
        InitList(); // 确保初始化
        r = L;
        std::cout << "输入" << n << "个数:" << "\n";
        for (int i = 0; i < n; i++)
        {
            p = new LNode;
            std::cin >> p->data;
            p->next = nullptr;
            r->next = p;
            r = p;
        }
    }

    auto GetHead()
    {
        return L;
    }
};
int main()
{
    int res, a, b;
    LinkedList<int> L; // 创建一个LinkedList实例
    std::cout << "链表已建立" << "\n";
    L.InitList(); // 初始化链表
    std::cout << "使用后插法创建链表" << "\n";
    L.CreateListR(5); // 创建链表

    std::cout << "要查找的位置: ";
    std::cin >> a;
    if (L.GetElem(a, res))
    {
        std::cout << "找到了，第" << a << "个数是" << res << "\n";
    }
    else
    {
        std::cout << "没找到" << "\n";
    }

    std::cout << "要查找的值: ";
    std::cin >> b;
    if (L.LocateElem(b))
    {
        std::cout << "找到" << "\n";
    }
    else
    {
        std::cout << "没找到，没有 " << b << "\n";
    }

    std::cout << "输入插入的位置和值: ";
    int c, d;
    std::cin >> c >> d;
    if (L.Insert(c, d))
    {
        std::cout << "插入成功" << "\n";
    }
    else
    {
        std::cout << "插入失败" << "\n";
    }

    std::cout << "要删除的位置: ";
    int f;
    std::cin >> f;
    if (L.Delete(f, res))
    {
        std::cout << "成功删除 " << res << "\n";
    }
    else
    {
        std::cout << "删除失败" << "\n";
    }

    std::cout << "链表输出: ";
    auto pos = L.GetHead()->next;
    while (pos)
    {
        std::cout << pos->data << " ";
        pos = pos->next;
    }
    std::cout << "\n";
    return 0;
}
