#ifndef SET_SET_H
#define SET_SET_H

#include <iostream>


template<typename T>
class Set
{
    struct Node
    {
        T value;
        Node* left;
        Node* right;
        Node* parent;

        explicit Node(const T& value_) : value(value_)
        { left = right = parent = nullptr; }

        ~Node()
        {
            delete right;
            delete left;
        }
    };

    size_t size_;
    Node* root;

public:

    class Iterator
    {
        Node* current;
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        Iterator() : current(nullptr){}
        explicit Iterator(Node* node) : current(node){}

        reference operator*() const
        {
            if (current != nullptr)
                return current->value;
            else
                throw std::runtime_error("nullptr dereference\n");
        }

        pointer operator->() const
        { return &current->value; }

        Iterator& operator++()
        {
            if (!current)
                throw std::runtime_error("nullptr increment\n");

            if (current->right)
            {
                Node* tmp = current->right;
                while (tmp->left)
                    tmp = tmp->left;
                current = tmp;
            }
            else
            {
                Node* tmp = current;
                while (tmp->parent && tmp == tmp->parent->right)
                    tmp = tmp->parent;
                if (tmp->parent)
                    current = tmp->parent;
                else
                    current = nullptr;
            }

            return *this;
        }

        Iterator operator++(int)
        {
            Iterator save(*this);

            if (!current)
                throw std::runtime_error("nullptr increment\n");

            if (current->right)
            {
                Node* tmp = current->right;
                while (tmp->left)
                    tmp = tmp->left;
                current = tmp;
            }
            else
            {
                Node* tmp = current;
                while (tmp->parent && tmp == tmp->parent->right)
                    tmp = tmp->parent;
                if (tmp->parent)
                    current = tmp->parent;
                else
                    current = nullptr;
            }

            return save;
        }

        friend bool operator==(Iterator lhs, Iterator rhs)
        { return lhs.current == rhs.current; }

        friend bool operator!=(Iterator lhs, Iterator rhs)
        { return lhs.current != rhs.current; }

        Node* getCurrent()
        { return current; }
    };

    explicit Set(const T& value_) : size_(0)
    { root = new Node(value_); }

    ~Set()
    { delete root; }

    Node* getRoot()
    { return root; }

    size_t size()
    { return size_;}

    void insert(const T& value_)
    {
        Node* tmp = root;
        while(true)
        {
            if (value_ < tmp->value)
            {
                if (tmp->left == nullptr)
                {
                    tmp->left = new Node(value_);
                    tmp->left->parent = tmp;
                    ++size_;
                }
                else
                    tmp = tmp->left;
            }
            else if (tmp->value < value_)
            {
                if (tmp->right == nullptr)
                {
                    tmp->right = new Node(value_);
                    tmp->right->parent = tmp;
                    ++size_;
                }
                else
                    tmp = tmp->right;
            }
            else
                break;
        }
    }

    void erase(Iterator pos)
    {
        if (!pos.getCurrent())
            throw std::runtime_error("nullptr erase\n");

        T val = *pos.operator->();

        Node* node = pos.getCurrent();

        if (node->left == nullptr && node->right == nullptr)
        {
            // Case 1: Node has no children
            if (node->parent)
            {
                if (node == node->parent->left)
                    node->parent->left = nullptr;
                else
                    node->parent->right = nullptr;

                delete node;
            }
            else
            {
                delete root;
                root = nullptr;
            }
        }
        else if (!node->left || !node->right)
        {
            // Case 2: Node has one child
            Node* child = (node->left) ? node->left : node->right;

            if (node->parent)
            {
                if (node == node->parent->left)
                    node->parent->left = child;
                else
                    node->parent->right = child;

                child->parent = node->parent;

                node->left = node->right = node->parent = nullptr;
                delete node;
            }
            else
            {
                root = child;
                child->parent = nullptr;
                delete node;
            }
        }
        else
        {
            // Case 3: Node has two children
            auto tmp = pos;
            ++tmp;
            Node* next = tmp.getCurrent();

            std::swap(node->value, next->value);
            erase(Iterator(next));
        }

    }

    void print_inorder(Node* current)
    {
        if (current->left)
            print_inorder(current->left);
        std::cout << current->value << " ";
        if (current->right)
            print_inorder(current->right);
    }

    void printTree(int distance, Node* current)
    {
        if (current->right)
            printTree(distance + 4, current->right);
        for (int i = 0; i < distance; ++i )
            std::cout.put(' ');
        std::cout << current->value << std::endl;
        if (current->left)
            printTree(distance + 4, current->left);
    }

    Iterator begin()
    {
        Node* tmp = root;
        while (tmp->left)
            tmp = tmp->left;
        return Iterator(tmp);
    }

    Iterator end()
    { return Iterator(); }

    Iterator find(const T& value_)
    {
        Node* current = root;

        while(true)
        {
            if (!current)
                return end();
            if (value_ < current->value)
                current = current->left;
            else if (current->value < value_)
                current = current->right;
            else
                return Iterator(current);
        }
    }

};

#endif //SET_SET_H