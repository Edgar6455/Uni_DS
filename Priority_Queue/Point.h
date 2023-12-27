#ifndef PQ_POINT_H
#define PQ_POINT_H

#include <cmath>

struct Point
{
    int x{};
    int y{};

    double dist() const
    {
        return std::sqrt(x * x + y * y);
    }

    friend bool operator>(const Point &lhs, const Point &rhs)
    {
        return (lhs.dist() > rhs.dist());
    }
};

#endif //PQ_POINT_H