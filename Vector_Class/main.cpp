#include <iostream>
#include <random>
#include "Vector.h"

void testFunctionality();

void solveProblem1();
Vector<int> implementationProblem1(const Vector<int>& nums, size_t size);

void solveProblem2();
Vector<int> implementationProblem2(const Vector<Vector<int>>& matrix, size_t n, size_t m);


int main()
{
    testFunctionality();
    solveProblem1();
    solveProblem2();

    return 0;
}

void solveProblem2()
{
    std::cout << "\n----------- Problem 2 ------------\n\n";

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 20);

    size_t n = 3, m = 4;
    Vector<Vector<int>> matrix(n, Vector<int>(m));

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            matrix[i][j] = dist(rd);

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "matrix[" << i << "]:\t  ";
        matrix[i].printInfo();
    }

    Vector<int> result = implementationProblem2(matrix, n, m);

    std::cout << "\nresult:\t  ";
    result.printInfo();

}

Vector<int> implementationProblem2(const Vector<Vector<int>>& matrix, size_t n, size_t m)
{
    Vector<int> result;


    for (size_t i = 0; i < n; ++i)
    {
        size_t rowMinIndex = 0;
        int rowMin = matrix[i][0];
        for (size_t j = 1; j < m; ++j)
        {
            if (matrix[i][j] < rowMin)
            {
                rowMinIndex = j;
                rowMin = matrix[i][j];
            }
        }

        bool happyNumber = true;
        for (size_t j = 0; j < n; ++j)
        {
            if (matrix[j][rowMinIndex] > rowMin)
            {
                happyNumber = false;
                break;
            }
        }

        if (happyNumber)
            result.push_back(rowMin);

    }

    return result;
}



void solveProblem1()
{
    std::cout << "\n----------- Problem 1 ------------\n\n";

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 5);

    size_t size = 5;

    Vector<int> nums(size);

    for (int i = 0; i < size; ++i)
        nums[i] = dist(rd);

    std::cout << "nums:\t  ";
    nums.printInfo();

    Vector<int> result = implementationProblem1(nums, size);

    std::cout << "result:\t  ";
    result.printInfo();
}


Vector<int> implementationProblem1(const Vector<int>& nums, size_t size)
{
    Vector<int> result(size, 1);

    int prefixMultiply = 1;
    for (int i = 0; i < size; ++i)
    {
        result[i] *= prefixMultiply;
        prefixMultiply *= nums[i];
    }

    int suffixMultiply = 1;
    for (int i = static_cast<int>(size) - 1; i >= 0; --i)
    {
        result[i] *= suffixMultiply;
        suffixMultiply *= nums[i];
    }

    return result;
}

void testFunctionality()
{
    std::cout << "\n-------- Functionality Test ---------\n\n";
    std::cout << "1. Constructor\n\n";

    Vector<int> v1(5, 0);
    Vector<int> v2(5);
    Vector<int> v3;

    std::cout << "v1:\t  ";
    v1.printInfo();

    std::cout << "v2:\t  ";
    v2.printInfo();

    std::cout << "v3:\t  ";
    v3.printInfo();


    std::cout << "\n2. Copy, move\n\n";

    Vector<int> v4(v1);
    Vector<int> v5(std::move(v1));

    Vector<int> v6 = v2;
    Vector<int> v7 = std::move(v2);


    std::cout << "v4:\t  ";
    v4.printInfo();

    std::cout << "v5:\t  ";
    v5.printInfo();

    std::cout << "v6:\t  ";
    v6.printInfo();

    std::cout << "v7:\t  ";
    v7.printInfo();


    std::cout << "\n3. [], at()\n\n";

    v7[4] = 5;
    std::cout << "v7[4]: " << v7.at(4) << std::endl;


    std::cout << "\n4. push_back(), pop_back()\n\n";

    v3.push_back(3);
    v3.push_back(6);

    std::cout << "v3:\t  ";
    v3.printInfo();

    v3.push_back(9);

    std::cout << "relocation:\n";
    std::cout << "v3:\t  ";
    v3.printInfo();

    v3.pop_back();

    std::cout << "v3:\t  ";
    v3.printInfo();


    std::cout << "\n5. clear(), empty()\n\n";

    std::cout << "v3:\t  ";
    v3.printInfo();
    std::cout << (v3.empty() ? "v3 is empty\n" : "v3 is not empty\n");

    v3.clear();
    std::cout << "v3:\t  ";
    v3.printInfo();

    std::cout << (v3.empty() ? "v3 is empty\n" : "v3 is not empty\n");
}