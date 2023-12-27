#include <iostream>

#include "Set.h"

int main()
{
    Set<int> s(7);
    s.insert(10);
    s.insert(5);
    s.insert(13);
    s.insert(2);
    s.insert(6);
    s.insert(12);
    s.insert(4);


    std::cout << "----------- Problem 1 ------------\n\n";

    std::cout << "Inorder traversal:\t\t";
    s.print_inorder(s.getRoot());
    std::cout << "\n";

    s.insert(9);
    std::cout << "After inserting 9:\t\t";
    s.print_inorder(s.getRoot());
    std::cout << "\n";


    std::cout << "\n----------- Problem 2 ------------\n\n";

    std::cout << "Range based for loop:\t";
    for (const auto& f : s)
        std::cout << f << " ";
    std::cout << "\n\n";

    std::cout << "Searching for 5:\t\t";
    auto it =  s.find(5);
    std::cout << ((it != s.end()) ? "found\n" : "not found\n");

    std::cout << "Searching for 14:\t\t";
    it =  s.find(14);
    std::cout << ((it != s.end()) ? "found\n" : "not found\n");


    std::cout << "\n----------- Problem 3 ------------\n\n";

    s.erase(s.find(6));
    std::cout << "After erasing 6:\t\t";
    s.print_inorder(s.getRoot());
    std::cout << "\n";

    return 0;
}