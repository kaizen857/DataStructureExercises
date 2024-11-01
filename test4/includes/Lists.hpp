#ifndef __LISTS_HPP_
#define __LISTS_HPP_
#include <stdexcept>
using namespace std;

template <typename T>
class Lists
{
private:
    struct node
    {
        T data;
        node *next;
        node *prev;
    };
    node *head = nullptr;
    node *tail = nullptr;
    int len;

public:
    class Iterator
    {
    private:
        node *p;

    public:
        Iterator(node *p)
        {
            this->p = p;
        }
        T &operator*()
        {
            return p->data;
        }
        T *operator->()
        {
            return &p->data;
        }
        Iterator &operator++()
        {
            p = p->next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            p = p->next;
            return tmp;
        }
        Iterator &operator--()
        {
            p = p->prev;
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator tmp = *this;
            p = p->prev;
            return tmp;
        }
        bool operator==(const Iterator &other) { return p == other.p; }
        bool operator!=(const Iterator &other) { return p != other.p; }
        friend class Lists;
    };
    friend class Iterator;
    Lists()
    {
        len = 0;
    }

    Lists(const Lists &l)
    {
        len = 0;
        if (l.head != nullptr)
        {
            node *pHc = l.head;
            head = new node();
            head->data = pHc->data;
            node *pH = head;
            len++;
            while (pHc != l.tail)
            {
                pHc = pHc->next;
                pH->next = new node();
                pH->next->prev = pH;
                pH = pH->next;
                pH->data = pHc->data;
                len++;
            }
        }
        else
        {
            head = tail = nullptr;
        }
    }

    Lists &operator=(const Lists &l)
    {
        len = 0;
        if (this == &l)
        {
            return *this;
        }
        len = 0;
        if (l.head != nullptr)
        {
            node *pHc = l.head;
            head = new node();
            head->data = pHc->data;
            node *pH = head;
            len++;
            while (pHc != l.tail)
            {
                pHc = pHc->next;
                pH->next = new node();
                pH->next->prev = pH;
                pH = pH->next;
                pH->data = pHc->data;
                len++;
            }
        }
        else
        {
            head = tail = nullptr;
        }
        return *this;
    }

    ~Lists()
    {
        node *bgn = head;
        while (head != tail)
        {
            head = head->next;
            delete bgn;
            bgn = head;
        }
        len = 0;
    }

    int size()
    {
        return len;
    }
    bool empty()
    {
        return len == 0;
    }
    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    void push_front(T data)
    {
        if (head == nullptr)
        {
            head = new node();
            head->data = data;
            len++;
            tail = head;
        }
        else
        {
            head->prev = new node();
            head->prev->data = data;
            len++;
            head->prev->next = head;
            head = head->prev;
        }
        return;
    }
    void push_back(T data)
    {
        if (head == nullptr)
        {
            head = new node();
            head->data = data;
            len++;
            tail = head;
        }
        else
        {
            tail->next = new node();
            tail->next->data = data;
            len++;
            tail->next->prev = tail;
            tail = tail->next;
        }
        return;
    }

    T operator[](int index)
    {
        node *p;
        p = head;
        if (index >= len)
            throw out_of_range("in at(int index) index out of range");
        else
        {
            for (int i = 0; i < index; i++)
                p = p->next;
        }
        return p->data;
    }

    // 查找节点
    int indexOf(T _data)
    {
        int index = 0;
        node *p = head;
        while (p->data != _data)
        {
            p = p->next;
            index++;
        }
        if (index >= len)
            return -1;
        else
            return index;
    }
    // 删除节点
    void removeAt(int index)
    {
        node *p;
        p = head;
        if (index >= len)
            throw out_of_range("in removeAt(int index) index out of range");
        else
        {
            // 移动到要删除的节点处
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            p = nullptr;
            len--;
        }
        return;
    }

    void remove(Iterator &it)
    {
        node *p = it.p;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        p = nullptr;
        len--;
        it.p = p;
    }

    void clear()
    {
        node *bgn = head;
        while (head != tail)
        {
            head = head->next;
            delete bgn; // 释放内存
            bgn = head;
        }
        len = 0;
    }

    // 交换两节点（交换值）
    void swap(int i, int j)
    {
        T vi = this->operator[](i);
        T vj = this->operator[](j);
        node *p;
        p = head;
        for (int k = 0; k < i; k++)
            p = p->next;
        p->data = vj;
        p = head;
        for (int k = 0; k < j; k++)
            p = p->next;
        p->data = vi;
    }

    // 子表划分函数，返回枢轴值
    int Partition(int low, int high)
    {
        T pivotkey;
        pivotkey = this->operator[](low); // 用子表的第一个记录作为枢轴记录
        while (low < high)
        {
            while (low < high && this->operator[](high) >= pivotkey)
                high--;
            swap(low, high);
            while (low < high && this->operator[](low) <= pivotkey)
                low++;
            swap(low, high);
        }
        return low;
    }

    // 快速排序递归函数
    void QSort(int low, int high)
    {
        int pivot;
        if (low < high)
        {
            pivot = Partition(low, high);
            QSort(low, pivot - 1);
            QSort(pivot + 1, high);
        }
    }
    // 快速排序
    void QuickSort()
    {
        QSort(0, len - 1);
    }
};

#endif // __LISTS_HPP_
