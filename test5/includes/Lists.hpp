#ifndef __LISTS_HPP_
#define __LISTS_HPP_
#include <stdexcept>

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
            throw std::out_of_range("in at(int index) index out of range");
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
            throw std::out_of_range("in removeAt(int index) index out of range");
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
    // 移除双链表中的指定元素，请注意当元素位于表头或表尾时，删除操作的正确性
    void remove(Iterator &it)
    {
        if (it.p == nullptr)
        {
            throw std::invalid_argument("in remove(Iterator &it) iterator is nullptr");
        }
        else if (it.p == head)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete it.p;
            it.p = nullptr;
            len--;
        }
        else if (it.p == tail)
        {
            tail = tail->prev;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            delete it.p;
            it.p = nullptr;
            len--;
        }
        else
        {
            it.p->prev->next = it.p->next;
            it.p->next->prev = it.p->prev;
            delete it.p;
            it.p = nullptr;
            len--;
        }
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

    auto find(const T &_data)
    {
        node *p = head;
        while (p != nullptr)
        {
            if (p->data == _data)
            {
                return Iterator(p);
            }
            p = p->next;
        }
        return Iterator(nullptr);
    }
};

#endif // __LISTS_HPP_
