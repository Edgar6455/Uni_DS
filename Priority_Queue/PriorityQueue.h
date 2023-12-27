#ifndef PQ_PRIORITYQUEUE_H
#define PQ_PRIORITYQUEUE_H

#include <iostream>
#include <vector>


template<typename T>
class PriorityQueue
{
private:
    std::vector<T> heap;

    int leftIndex(int index)
    { return index * 2 + 1; }

    int rightIndex(int index)
    { return index * 2 + 2; }

    int parentIndex(int index)
    { return (index - 1) / 2; }

    void siftUp(int index)
    {
        if (!index)
            return;

        int P = parentIndex(index);

        siftDown(P);

        int PP = parentIndex(P);
        if (heap[P] > heap[PP])
            siftUp(P);
    }

    void siftDown(int index)
    {
        int L = leftIndex(index), R = rightIndex(index);

        // Has no child nodes
        if (L >= heap.size() && R >= heap.size())
            return;

        // Left child node only
        if (R >= heap.size() && heap[L] > heap[index])
        {
            std::swap(heap[L], heap[index]);
            siftDown(L);
        }

        // Both children exist
        if (R < heap.size() && (heap[L] > heap[index] || heap[R] > heap[index]))
        {
            int maxChildIndex = (heap[L] > heap[R]) ? L : R;

            if (heap[maxChildIndex] > heap[index])
            {
                std::swap(heap[index], heap[maxChildIndex]);
                siftDown(maxChildIndex);
            }
        }

    }

    void printTree(int currentIndex, int indent = 0)
    {
        if (currentIndex >= heap.size())
            return;

        printTree(rightIndex(currentIndex), indent + 2);
        std::cout << std::string(indent * 3, ' ') << heap[currentIndex] << std::endl;
        printTree(leftIndex(currentIndex), indent + 2);
    }

public:

    PriorityQueue() = default;

    template<typename InputIt>
    PriorityQueue(InputIt first, InputIt last) : heap(first, last) // O(N)
    {
        int LastInternalNode = (heap.size() / 2) - 1;

        for (int i = LastInternalNode; i >= 0; --i)
            siftDown(i);

    }

    bool empty() const // O(1)
    { return heap.empty(); }

    size_t size() const // O(1)
    { return heap.size(); }

    void push(const T& value) // O(log(N))
    {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void pop() // O(log(N))
    {
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();

        siftDown(0);
    }

    const T& top() const // O(1)
    {
        if (!empty())
            return heap[0];
        throw std::runtime_error("Empty priority queue top access");
    }

    void displayTree()
    {
        if (empty())
        {
            std::cout << "empty\n";
            return;
        }

        std::cout << "-------------------------\n";
        printTree(0);
        std::cout << "-------------------------\n\n";
    }

};


#endif //PQ_PRIORITYQUEUE_H