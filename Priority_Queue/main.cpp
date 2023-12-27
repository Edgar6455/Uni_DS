#include <iostream>
#include <vector>

#include "PriorityQueue.h"
#include "Point.h"

void TestPQFunctionality();
void solveProblem1();
void solveProblem2();

int implementationProblem1(const std::vector<int>& piles, int k);
std::vector<Point> implementationProblem2(const std::vector<Point>& points, int k);


int main()
{
    TestPQFunctionality();
    solveProblem1();
    solveProblem2();
}


void solveProblem1()
{
    std::cout << std::endl << "\n\n------------ Problem 1 ------------\n\n";

    std::vector<int> piles{5, 4, 9};
    int k = 2;

    std::cout << "Input: piles = [";
    for (int i = 0; i < piles.size(); ++i)
    {
        std::cout << piles[i];
        if (i != piles.size() - 1)
            std::cout << ", ";
    }
    std::cout << "], k = " << k << "\n";

    int result = implementationProblem1(piles, k);
    std::cout << "Output: " << result << "\n\n";

    piles = {4, 3, 6, 7};
    k = 3;

    std::cout << "Input: piles = [";
    for (int i = 0; i < piles.size(); ++i)
    {
        std::cout << piles[i];
        if (i != piles.size() - 1)
            std::cout << ", ";
    }
    std::cout << "], k = " << k << "\n";

    result = implementationProblem1(piles, k);
    std::cout << "Output: " << result << "\n\n";
}

void solveProblem2()
{
    std::cout << "\n------------ Problem 2 ------------\n\n";

    std::vector<Point> points{{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    std::cout << "Input: points = [";
    for (int i = 0; i < points.size(); ++i)
    {
        std::cout << "[" << points[i].x << ", " << points[i].y << "]";
        if (i != points.size() - 1)
            std::cout << ", ";
    }
    std::cout << "], k = " << k << "\n";

    std::vector<Point> result = implementationProblem2(points, k);
    std::cout << "Output: [";
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << "[" << result[i].x << ", " << result[i].y << "]";
        if (i != result.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";

}

int implementationProblem1(const std::vector<int>& piles, int k)
{
    PriorityQueue<int> pq(piles.begin(), piles.end());

    for (int i = 0; i < k; ++i)
    {
        int pileToDecrease = pq.top();
        pileToDecrease -= pileToDecrease / 2;
        pq.pop();
        pq.push(pileToDecrease);
    }

    int result = 0;
    while(!pq.empty())
    {
        result += pq.top();
        pq.pop();
    }

    return result;
}


std::vector<Point> implementationProblem2(const std::vector<Point>& points, int k)
{
    PriorityQueue<Point> pq;

    for (const Point& point : points) {
        if (pq.size() < k)
        {
            pq.push(point);
            continue;
        }

        if (point.dist() < pq.top().dist())
        {
            pq.pop();
            pq.push(point);
        }
    }

    std::vector<Point> result;
    while (!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

void TestPQFunctionality()
{
    std::vector<int> v{1, 5, 3, 10, -2, -4, 7, 2, 6, -5};
    PriorityQueue<int> pq1(v.begin(), v.end());

    std::cout << "pq1:\n";
    pq1.displayTree();

    std::cout << "pq1.empty() = " << std::boolalpha << pq1.empty() << "\n";
    std::cout << "pq1.top() = " << pq1.top() << "\npq1.pop()\n";
    pq1.pop();

    std::cout << "pq1:\n";
    pq1.displayTree();

    std::cout << "pq1.push(4)\n";
    pq1.push(4);
    std::cout << "pq1:\n";
    pq1.displayTree();

    PriorityQueue<int> pq2;
    std::cout << "pq2:\n";
    std::cout << "pq2.empty() = " << std::boolalpha << pq2.empty() << "\n";
}
