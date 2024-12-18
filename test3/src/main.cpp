#include <bits/stdc++.h>

typedef int Elemtype;
typedef struct LNode
{
    Elemtype data;
    LNode *next;
} LNode, *Linklist;

bool InitList(Linklist &L)
{
    L = new LNode;
    L->next = NULL;
    return true;
}
bool GetElem(Linklist &L, int i, Elemtype &e)
{
    int j = 1;
    LNode *p;
    p = L->next;
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
LNode *LocateElem(Linklist L, Elemtype e)
{
    LNode *p;
    p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}
bool Insert(Linklist L, int i, Elemtype &e)
{
    int j = 0;
    LNode *p, *s;
    p = L;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
        return false;
    }
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool Delete(Linklist &L, int i, Elemtype &e)
{
    LNode *p, *q;
    int j = 0;
    p = L;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next || j > i - 1))
    {
        return false;
    }
    q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return true;
}
void CreateListH(Linklist &L, int n)
{
    LNode *p;
    L = new LNode;
    L->next = NULL;

    for (int i = 0; i < n; i++)
    {
        p = new LNode;
        std::cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

void CreateListR(Linklist &L, int n)
{
    LNode *r, *p;
    L = new LNode;
    L->next = NULL;
    r = L;
    std::cout << "输入" << n << "个数:" << "\n";
    for (int i = 0; i < n; i++)
    {
        p = new LNode;
        std::cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
int main()
{
    int res, a, b, choose = 0;
    LNode *L, *p;
    std::cout << "链表已建立" << "\n";
    InitList(L);
    std::cout << "使用后插法创建链表" << "\n";
    CreateListR(L, 5);
    std::cout << "要查找的位置";
    std::cin >> a;
    if (GetElem(L, a, res))
    {
        std::cout << "找到了，第" << a << "个数是" << res << "\n";
    }
    else
    {
        std::cout << "没找到" << "\n";
    }
    std::cout << "要查找的值";
    std::cin >> b;
    if (LocateElem(L, b))
    {
        std::cout << "找到" << "\n";
    }
    else
    {
        std::cout << "没找到，没有  " << b << "\n";
    }
    std::cout << "输入插入的位置和值";
    int c, d;
    std::cin >> c >> d;
    if (Insert(L, c, d))
    {
        std::cout << "插入成功" << "\n";
    }
    else
    {
        std::cout << "插入失败" << "\n";
    }
    std::cout << "要删除的位置";
    int f;
    std::cin >> f;
    if (Delete(L, f, res))
    {
        std::cout << "成功删除  " << res << "\n";
    }
    else
    {
        std::cout << "删除失败" << "\n";
    }
    std::cout << "链表输出";
    p = L->next;
    while (p)
    {
        std::cout << p->data;
        p = p->next;
    }
    return 0;
}
