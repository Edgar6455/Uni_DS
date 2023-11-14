#ifndef LINKEDLIST_DLINKEDLIST_H
#define LINKEDLIST_DLINKEDLIST_H

#include <iostream>
#include <initializer_list>
#include <algorithm>

template<typename T>
class List
{
    struct Node
    {
        T value;
        Node* next;
        Node* prev;

        Node() : next(nullptr), prev(nullptr){}
        explicit Node(T value_) : value(value_), next(nullptr), prev(nullptr){}
        explicit Node(Node* prev_) : next(nullptr), prev(prev_)
        { prev_->next = this; }
        Node(T value_, Node* prev_) : value(value_), next(nullptr), prev(prev_)
        { prev_->next = this; }

        ~Node()
        { delete next; }
    };

    Node *head;
    Node *tail;
    size_t size_;

public:
    class iterator
    {
    private:
        Node* current;
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

        iterator() : current(nullptr){}

        iterator(Node *node) : current(node){}

        Node*& getCurrentNode()
        { return current; }

        reference operator*() const
        {
            if (current != nullptr)
                return current->value;
            else
                throw std::runtime_error("nullptr dereference");
        }

        pointer operator->() const
        { return &current->value; }

        iterator& operator++()
        {
            if (current != nullptr)
            {
                current = current->next;
                return *this;
            }
            else
                throw std::runtime_error("nullptr increment");
        }

        iterator &operator++(int)
        {
            if (current != nullptr)
            {
                iterator tmp = this;
                current = current->next;
                return *tmp;
            }
            else
                throw std::runtime_error("nullptr increment");
        }

        iterator &operator--()
        {
            if (current != nullptr)
            {
                current = current->prev;
                return *this;
            }
            else
                throw std::runtime_error("nullptr decrement");
        }

        iterator &operator--(int)
        {
            if (current != nullptr)
            {
                iterator tmp = this;
                current = current->prev;
                return *tmp;
            }
            else
                throw std::runtime_error("nullptr decrement");
        }

        friend bool operator==(iterator lhs, iterator rhs)
        { return lhs.current == rhs.current; }

        friend bool operator!=(iterator lhs, iterator rhs)
        { return lhs.current != rhs.current; }
    };

    // Constructors
    List() : size_(0), head(new Node()), tail(new Node(head)) {}

    explicit List(size_t count, const T& value = T{}) : size_(count)
    {
        if (count)
        {
            head = new Node();
            Node* tmp = head;

            for (int i = 0; i < count; ++i)
                tmp = new Node(value, tmp);

            tail = new Node(tmp);
        }
    }

    List(std::initializer_list<T> iList) : size_(iList.size())
    {
        head = new Node();
        Node* tmp = head;

        for (auto value : iList)
            tmp = new Node(value, tmp);

        tail = new Node(tmp);
    }

    List(const List& other) : size_(other.size_)
    {
        head = new Node();
        Node* tmp = head;
        Node* otherTmp = other.head;

        for (int i = 0; i < other.size_; ++i)
        {
            otherTmp = otherTmp->next;
            T value = otherTmp->value;
            tmp = new Node(value, tmp);
        }

        tail = new Node(tmp);
    }

    List(List&& other)
    {
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
        size_ = other.size_;
        other.size_ = 0;
    }

    // Destructor
    ~List()
    { delete head; }

    // Operators
    List& operator=(const List& other)
    {
        if (&other == this)
            return *this;

        delete head;
        size_ = other.size_;

        head = new Node();
        Node* tmp = head;
        Node* otherTmp = other.head;

        for (int i = 0; i < other.size_; ++i)
        {
            otherTmp = otherTmp->next;
            T value = otherTmp->value;
            tmp = new Node(value, tmp);
        }

        tail = new Node(tmp);
    }

    List& operator=(List&& other)
    {
        if (&other == this)
            return *this;

        delete head;

        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
        size_ = other.size_;
        other.size_ = 0;
    }

    List& operator=(std::initializer_list<T> iList)
    {
        delete head;

        head = new Node();
        Node* tmp = head;

        for (auto value : iList)
            tmp = new Node(value, tmp);

        tail = new Node(tmp);
    }

    friend bool operator==(const List<int>& lhs, const List<T> &rhs)
    {
        if (lhs.size_ != rhs.size_)
            return false;

        Node* lhs_tmp = lhs.head->next;
        Node* rhs_tmp = rhs.head->next;

        while(lhs_tmp != lhs.tail)
        {
            if (lhs_tmp->value != rhs_tmp->value)
                return false;

            lhs_tmp = lhs_tmp->next;
            rhs_tmp = rhs_tmp->next;
        }

        return true;
    }

    // Element access
    T& front()
    { if (size_) return head->next->value; }

    const T& front() const
    { if (size_) return head->next->value; }

    T& back()
    { if (size_) return tail->prev->value; }

    const T& back() const
    { if (size_) return tail->prev->value; }

    // Capacity
    bool empty() const
    { return size_ == 0; }

    size_t size() const
    { return size_; }

    // Modifiers
    void push_front(const T& value)
    {
        Node* tmp = new Node(value);
        ++size_;

        head->next->prev = tmp;
        tmp->next = head->next;

        head->next = tmp;
        tmp->prev = head;
    }

    void push_front(T&& value)
    {
        Node* tmp = new Node(std::move(value));
        ++size_;

        head->next->prev = tmp;
        tmp->next = head->next;

        head->next = tmp;
        tmp->prev = head;
    }

    void push_back(const T& value)
    {
        Node* tmp = new Node(value);
        ++size_;

        tail->prev->next = tmp;
        tmp->prev = tail->prev;

        tail->prev = tmp;
        tmp->next = tail;
    }

    void push_back(T&& value)
    {
        Node* tmp = new Node(std::move(value));
        ++size_;

        tail->prev->next = tmp;
        tmp->prev = tail->prev;

        tail->prev = tmp;
        tmp->next = tail;
    }

    void pop_front()
    {
        if (empty())
            throw std::runtime_error("poping empty list");

        Node* erased = head->next;
        --size_;

        head->next->next->prev = head;
        head->next = head->next->next;

        erased->next = nullptr;
        erased->prev = nullptr;

        delete erased;
    }

    void pop_back()
    {
        if (empty())
            throw std::runtime_error("poping empty list");

        Node* erased = tail->prev;
        --size_;

        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;

        erased->next = nullptr;
        erased->prev = nullptr;

        delete erased;
    }

    iterator insert(iterator pos, const T& value)
    {
        if (pos.getCurrentNode() == nullptr)
            return iterator();

        Node* tmp = new Node(value);
        size_++;

        pos.getCurrentNode()->prev->next = tmp;
        tmp->prev = pos.getCurrentNode()->prev;

        pos.getCurrentNode()->prev = tmp;
        tmp->next = pos.getCurrentNode();
    }

    iterator insert(iterator pos, T&& value)
    {
        if (pos.getCurrentNode() == nullptr)
            return iterator();

        Node* tmp = new Node(std::move(value));
        size_++;

        pos.getCurrentNode()->prev->next = tmp;
        tmp->prev = pos.getCurrentNode()->prev;

        pos.getCurrentNode()->prev = tmp;
        tmp->next = pos.getCurrentNode();

        return iterator(tmp);
    }

    iterator insert(iterator pos, std::initializer_list<T> iList)
    {
        if (pos.getCurrentNode() == nullptr)
            return iterator();

        Node* tmp;
        size_ += iList.size();

        for (auto value : iList)
        {
            tmp = new Node(value);

            pos.getCurrentNode()->prev->next = tmp;
            tmp->prev = pos.getCurrentNode()->prev;

            pos.getCurrentNode()->prev = tmp;
            tmp->next = pos.getCurrentNode();
        }

        return iterator(tmp);
    }

    iterator erase(iterator pos)
    {
        if (pos.getCurrentNode() == nullptr || pos.getCurrentNode() == tail || pos.getCurrentNode() == head)
            return iterator();

        --size_;
        iterator res = pos;
        ++res;

        pos.getCurrentNode()->prev->next = pos.getCurrentNode()->next;
        pos.getCurrentNode()->next->prev = pos.getCurrentNode()->prev;

        pos.getCurrentNode()->next = nullptr;
        pos.getCurrentNode()->prev = nullptr;

        delete pos.getCurrentNode();

        return res;
    }

    iterator erase(iterator first, iterator last)
    {
        if (first.getCurrentNode() == nullptr || first.getCurrentNode() == head ||
            last.getCurrentNode() == nullptr || last.getCurrentNode() == head)
            return iterator();

        iterator res = last;
        iterator tmp = first, tmp2 = first;

        while(tmp != last)
        {
            --size_;
            ++tmp2;

            tmp.getCurrentNode()->prev->next = tmp.getCurrentNode()->next;
            tmp.getCurrentNode()->next->prev = tmp.getCurrentNode()->prev;

            tmp.getCurrentNode()->next = nullptr;
            tmp.getCurrentNode()->prev = nullptr;

            delete tmp.getCurrentNode();

            tmp = tmp2;
        }

        return res;
    }

    // Iterators
    iterator begin()
    {
        iterator it;

        if (size_)
            it = head->next;

        return it;
    }

    iterator end()
    { return iterator(tail); }

    // Additional

    void printState()
    {
        std::cout << "size: " << size() <<".\t\t[<H>, ";
        Node* tmp;

        if (size())
            tmp = head -> next;

        for (int i = 0; i < size_; ++i)
        {
            std::cout << tmp->value;
            std::cout << ", ";
            tmp = tmp->next;
        }

        std::cout << "<T>]" << std::endl;
    }
};


#endif //LINKEDLIST_DLINKEDLIST_H