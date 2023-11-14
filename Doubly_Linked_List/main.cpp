#include <iostream>
#include <algorithm>
#include <random>
#include "DLinkedList.h"

void testFunctionality();

void solveProblem1();
void solveProblem2();
void solveProblem3();

template <typename T>
void implementationProblem1(List<T>& ls, const T& x);
void implementationProblem2(List<char>& ls);
template<typename InputIt, typename T>
bool implementationProblem3(InputIt first, InputIt last, const T &value); // search()

int main()
{
    testFunctionality();

    solveProblem1();
    solveProblem2();
    solveProblem3();

    return 0;
}

void solveProblem1()
{
    std::cout << "\n----------- Problem 1 ------------\n\n";

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 9);

    int size = 7;
    List<int> l;

    for (int i = 0; i < size; ++i)
    {
        l.push_back(dist(rd));
    }
    std::cout << "l:\t    ";
    l.printState();

    auto it = l.begin();
    ++it;
    ++it;
    ++it;
    int x = *it;
    std::cout << "x = " << x << std::endl;

    implementationProblem1(l, x);
    std::cout << "l:\t    ";
    l.printState();


    List<char> l2;

    std::uniform_int_distribution<int> dist2(97, 105);
    for (int i = 0; i < size; ++i)
    {
        l2.push_back(static_cast<char>(dist2(rd)));
    }
    std::cout << "\nl2:\t    ";
    l2.printState();

    auto it2 = l2.begin();
    ++it2;
    ++it2;
    ++it2;
    char x_ = *it2;
    std::cout << "x = " << x_ << std::endl;

    implementationProblem1(l2, x_);
    std::cout << "l2:\t    ";
    l2.printState();
}

template <typename T>
void implementationProblem1(List<T>& ls, const T& x)
{
    auto before = std::find(ls.begin(), ls.end(), x);
    auto after = before;
    ++after;

    auto it = ls.begin();

    while(it != before)
    {
        if (*it > x)
        {
            ls.insert(after, *it);
            it = ls.erase(it);
        }
        else
            ++it;
    }

    while(it != ls.end())
    {
        if (*it < x)
        {
            ls.insert(before, *it);
            it = ls.erase(it);
        }
        else
            ++it;
    }

}


void solveProblem2()
{
    std::cout << "\n----------- Problem 2 ------------\n\n";

    //    Input:  list = [a, a, b, c, c, c]
    //    Output: list = [A, b, C]

    List<char> l = {'a', 'a', 'b', 'c', 'c', 'c'};
    std::cout << "l:\t    ";
    l.printState();

    implementationProblem2(l);

    std::cout << "l:\t    ";
    l.printState();

    //    Input:  list = [d, f, f, r, r, d]
    //    Output: list = [d, F, R, d]

    List<char> l2 = {'d', 'f', 'f', 'r', 'r', 'd'};
    std::cout << "\nl2:\t    ";
    l2.printState();

    implementationProblem2(l2);

    std::cout << "l2:\t    ";
    l2.printState();

}

void implementationProblem2(List<char>& ls)
{
    auto it = ls.begin();
    auto it2 = ls.begin();

    bool change = false;
    char last = 0;

    while(true)
    {
        if (it == ls.end() && change)
        {
            it = ls.erase(it2, it);
            ls.insert(it, static_cast<char>(last - ('a' - 'A')));
            break;
        }

        if (it == ls.end())
            break;

        if (*it != last && !change)
            it2 = it;

        if (*it != last && change)
        {
            it = ls.erase(it2, it);
            ls.insert(it, static_cast<char>(last - ('a' - 'A')));
            it2 = it;
            change = false;
        }

        if (*it == last)
            change = true;

        last = *it;
        ++it;
    }
}


void solveProblem3()
{
    std::cout << "\n----------- Problem 3 ------------\n\n";

    List<int> l = {3, 5, 20, 42, 94};
    std::cout << "l:\t    ";
    l.printState();

    std::cout << ((implementationProblem3(l.begin(), l.end(), 42)) ? "\n42 found in list\n" : "\n42 not found in list\n");
    std::cout << ((implementationProblem3(l.begin(), l.end(), 5)) ? "5 found in list\n" : "5 not found in list\n");
    std::cout << ((implementationProblem3(l.begin(), l.end(), 7)) ? "7 found in list\n" : "7 not found in list\n");


    std::vector<int> v = {1, 4, 7, 12, 17, 26};
    std::cout << "\nv:\t    size: 6.\t\t[1, 4, 7, 12, 17, 26]" << std::endl;

    std::cout << ((implementationProblem3(v.begin(), v.end(), 17)) ? "\n17 found in vector\n" : "\n17 not found in vector\n");
    std::cout << ((implementationProblem3(v.begin(), v.end(), 7)) ? "7 found in vector\n" : "7 not found in vector\n");
    std::cout << ((implementationProblem3(v.begin(), v.end(), 20)) ? "20 found in vector\n" : "20 not found in vector\n");

}

template<typename It, typename T>
bool implementationProblem3(It first, It last, const T &value) // search
{
    if constexpr (std::is_same_v<typename std::iterator_traits<It>::iterator_category, std::random_access_iterator_tag>)
    {
        while (first <= last)
        {
            It mid = first + (last - first - 1) / 2;

            if (*mid == value)
                return true; // found

            else if (value > *mid)
                first = mid + 1;

            else
                last = mid - 1;
        }

        return false; // not found
    }

    else if constexpr (std::is_same_v<typename std::iterator_traits<It>::iterator_category, std::bidirectional_iterator_tag>)
    {
        while (true)
        {
            It mid = std::next(first, (std::distance(first, last) - 1) / 2);

            if (*mid == value)
                return true; // found

            if (first == last)
                break;

            else if (value > *mid)
                first = ++mid;

            else
                last = --mid;
        }

        return false; // not found
    }
}


void testFunctionality()
{
    std::cout << "\n-------- Functionality Test ---------\n\n";
    std::cout << "1. Constructors\n\n";

    List<int> l1;
    std::cout << "l1:\t    ";
    l1.printState();

    List<int> l2(4, 2);
    std::cout << "l2:\t    ";
    l2.printState();

    List<int> l3 = {4, 6, 7};
    std::cout << "l3:\t    ";
    l3.printState();

    List<int> l4(l3);
    std::cout << "\nl4:\t    ";
    l4.printState();

    List<int> l5(std::move(l4));
    std::cout << "l5:\t    ";
    l5.printState();


    std::cout << "\n2. Operators\n\n";

    l5 = l2;
    std::cout << "l5:\t    ";
    l5.printState();

    List<int> l6 = std::move(l3);
    std::cout << "l6:\t    ";
    l6.printState();

    std::cout << "\nl2:\t    ";
    l2.printState();
    std::cout << ((l2 == l5) ? "\nl2 == l5" : "\nl2 != l5") << std::endl;
    std::cout << ((l5 == l6) ? "l5 == l6" : "l5 != l6") << std::endl;


    std::cout << "\n3. Element access\n\n";

    std::cout << "l6:\t    ";
    l6.printState();

    std::cout << "\nl6.front() = " << l6.front() << std::endl;
    std::cout << "l6.back() = " << l6.back() << std::endl;


    std::cout << "\n4. Empty\n\n";

    std::cout << "l1:\t    ";
    l1.printState();
    std::cout << "l6:\t    ";
    l6.printState();

    std::cout << ((l1.empty()) ? "\nl1 is empty" : "\nl1 is not empty") << std::endl;
    std::cout << ((l6.empty()) ? "l6 is empty" : "l6 is not empty") << std::endl;


    std::cout << "\n5. Modifiers\n\n";

    int x = 8;
    l5.push_back(x);
    std::cout << "l5:\t    ";
    l5.printState();

    l5.push_front(3);
    std::cout << "l5:\t    ";
    l5.printState();

    l6.pop_back();
    std::cout << "\nl6:\t    ";
    l6.printState();

    l6.pop_front();
    std::cout << "l6:\t    ";
    l6.printState();


    std::cout << "\n6. Iterators, insert and erase\n\n";

    auto it = l6.end();
    l6.insert(it, 7);
    std::cout << "l6:\t    ";
    l6.printState();

    it = l6.begin();
    l6.insert(it, 4);
    std::cout << "l6:\t    ";
    l6.printState();

    ++it;
    std::cout << "\n*it = " << *it << std::endl;

    l6.insert(it, {1, 2});
    std::cout << "l6:\t    ";
    l6.printState();

    --it;
    --it;
    std::cout << "\n*it = " << *it << std::endl;
    it = l6.erase(it);
    std::cout << "l6:\t    ";
    l6.printState();

    std::cout << "\n*it = " << *it << std::endl;

    auto it2 = l6.begin();
    std::cout << "*it2 = " << *it2 << std::endl;
    l6.erase(it2, it);
    std::cout << "l6:\t    ";
    l6.printState();

}