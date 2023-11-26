#include <iostream>
#include <set>
#include <map>
#include <vector>

#include "Trie.h"
#include "BinaryTree.h"

#include <random>
#include <sstream>
#include <algorithm>
#include <queue>


void solveSetProblem1();
void solveSetProblem2();
void solveSetProblem3();

void solveMapProblem1();
void solveMapProblem2();
void solveMapProblem3();
void solveMapProblem4();
void solveMapProblem5();
void solveMapProblem6();
void solveMapProblem7();

std::size_t implementationSetProblem1(std::vector<int> v, int size);
int implementationSetProblem2(const std::string& jewels, const std::string& stones);
int implementationSetProblem3(const std::string& str, std::string& substr);

int implementationMapProblem1(const std::string& str);
int implementationMapProblem2(const std::string& str, std::string& palindrome);
bool implementationMapProblem3(const std::vector<int>& nums, int k);
bool implementationMapProblem4(const std::string& pattern, const std::string& s);
std::string implementationMapProblem5(const std::string& s);
std::vector<int> implementationMapProblem7(TreeNode* root);


int main()
{
    solveSetProblem1();
    solveSetProblem2();
    solveSetProblem3();

    solveMapProblem1();
    solveMapProblem2();
    solveMapProblem3();
    solveMapProblem4();
    solveMapProblem5();
    solveMapProblem6();
    solveMapProblem7();

    return 0;
}


void solveSetProblem1()
{
    std::cout << "\n----------- Set: Problem 1 ------------\n\n";

    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 5);

    int size = 7;
    std::vector<int> v;

    std::cout << "Total count: " << size << "\nNumbers: ";

    for (int i = 0; i < size; ++i)
    {
        v.push_back(dist(rd));
        std::cout << v[i] << ((i == size - 1) ? "\n" : ", ");
    }

    std::size_t ans = implementationSetProblem1(v, size);

    std::cout << "Unique numbers count: " << ans << "\n";
}

void solveSetProblem2()
{
    std::cout << "\n----------- Set: Problem 2 ------------\n\n";

    std::string jewels, stones;

    jewels = "aA", stones = "aAAbbbb";
    std::cout << "Input: jewels = \"" << jewels << "\", stones = \"" << stones << "\"\n";


    int result = implementationSetProblem2(jewels, stones);
    std::cout << "Output: " << result << "\n\n";


    jewels = "z", stones = "ZZ";
    std::cout << "Input: jewels = \"" << jewels << "\", stones = \"" << stones << "\"\n";

    result = implementationSetProblem2(jewels, stones);
    std::cout << "Output: " << result << "\n";
}


void solveSetProblem3()
{
    std::cout << "\n----------- Set: Problem 3 ------------\n\n";

    std::string s, substr;

    s = "abcabcbb";
    std::cout << "Input: s = \"" << s << "\"\n";

    int result = implementationSetProblem3(s, substr);
    std::cout << "Output: " << result << "\n";
    std::cout << "Explanation: The answer is \"" << substr << "\", with the length of " << result << ".\n\n";


    s = "bbbbb";
    std::cout << "Input: s = \"" << s << "\"\n";

    result = implementationSetProblem3(s, substr);
    std::cout << "Output: " << result << "\n";
    std::cout << "Explanation: The answer is \"" << substr << "\", with the length of " << result << ".\n\n";


    s = "pwwkew";
    std::cout << "Input: s = \"" << s << "\"\n";

    result = implementationSetProblem3(s, substr);
    std::cout << "Output: " << result << "\n";
    std::cout << "Explanation: The answer is \"" << substr << "\", with the length of " << result << ".\n";
}

void solveMapProblem1()
{
    std::cout << "\n\n----------- Map: Problem 1 ------------\n\n";

    std::string s, substr;

    s = "apple";
    std::cout << "Input: s = \"" << s << "\"\n";

    int result = implementationMapProblem1(s);
    std::cout << "Output: " << result << "\n\n";


    s = "staticanalysis";
    std::cout << "Input: s = \"" << s << "\"\n";

    result = implementationMapProblem1(s);
    std::cout << "Output: " << result << "\n\n";


    s = "aabb";
    std::cout << "Input: s = \"" << s << "\"\n";

    result = implementationMapProblem1(s);
    std::cout << "Output: " << result << "\n";
}

void solveMapProblem2()
{
    std::cout << "\n----------- Map: Problem 2 ------------\n\n";

    std::string s, palindrome;

    s = "acbcccdd";
    std::cout << "Input: s = \"" << s << "\"\n";

    int result = implementationMapProblem2(s, palindrome);
    std::cout << "Output: " << result << "\n";
    std::cout << "Explanation: One longest palindrome that can be built is \"" << palindrome << "\", with the length of " << result << ".\n";
}

void solveMapProblem3()
{
    std::cout << "\n----------- Map: Problem 3 ------------\n\n";

    std::vector<int> nums = <%1, 2, 3, 1%>;
    int k = 3;
    std::cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i)
    <%
        std::cout << nums<:i:>;
        if (i != nums.size() - 1)
            std::cout << ", ";
    %>
    std::cout << "], k = " << k << "\n";

    bool result = implementationMapProblem3(nums, k);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    nums = <%1, 0, 1, 1%>;
    k = 1;
    std::cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i)
    <%
        std::cout << nums<:i:>;
        if (i != nums.size() - 1)
            std::cout << ", ";
    %>
    std::cout << "], k = " << k << "\n";

    result = implementationMapProblem3(nums, k);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    nums = <%1, 2, 3, 1, 2, 3%>;
    k = 2;
    std::cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); ++i)
    <%
        std::cout << nums<:i:>;
        if (i != nums.size() - 1)
            std::cout << ", ";
    %>
    std::cout << "], k = " << k << "\n";

    result = implementationMapProblem3(nums, k);
    std::cout << "Output: " << std::boolalpha << result << "\n";
}

void solveMapProblem4()
{
    std::cout << "\n----------- Map: Problem 4 ------------\n\n";
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";
    std::cout << "Input: pattern = \"" << pattern << "\", s = \"" << s << "\"\n";

    bool result = implementationMapProblem4(pattern, s);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    pattern = "abba";
    s = "dog cat cat fish";
    std::cout << "Input: pattern = \"" << pattern << "\", s = \"" << s << "\"\n";

    result = implementationMapProblem4(pattern, s);
    std::cout << "Output: " << std::boolalpha << result << "\n\n";


    pattern = "aaaa";
    s = "dog cat cat dog";
    std::cout << "Input: pattern = \"" << pattern << "\", s = \"" << s << "\"\n";

    result = implementationMapProblem4(pattern, s);
    std::cout << "Output: " << std::boolalpha << result << "\n";
}

void solveMapProblem5()
{
    std::cout << "\n----------- Map: Problem 5 ------------\n\n";

    std::string s, result;

    s = "tree";
    std::cout << "Input: s = \"" << s << "\"\n";

    result = implementationMapProblem5(s);
    std::cout << "Output: \"" << result << "\"\n\n";


    s = "cccaaa";
    std::cout << "Input: s = \"" << s << "\"\n";

    result = implementationMapProblem5(s);
    std::cout << "Output: \"" << result << "\"\n\n";


    s = "Aabb";
    std::cout << "Input: s = \"" << s << "\"\n";

    result = implementationMapProblem5(s);
    std::cout << "Output: \"" << result << "\"\n";
}

void solveMapProblem6()
{
    std::cout << "\n----------- Map: Problem 6 ------------\n\n";

    Trie trie;
    trie.insert("Hello");
    trie.insert("Hey");
    trie.insert("World");

    std::cout << "Containing a word starting with...\n";
    std::cout << "Hell:\t" << trie.startsWith("Hell") << "\n"; // Output: true
    std::cout << "abc:\t" << trie.startsWith("abc") << "\n";  // Output: false
    std::cout << "Wo:\t\t" << trie.startsWith("Wo") << "\n";  // Output: true
}

void solveMapProblem7()
{
    std::cout << "\n----------- Map: Problem 7 ------------\n\n";

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);

    updateTreeSums(root);

    std::vector<int> result = implementationMapProblem7(root);

    std::cout << "Output = [";
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i];
        if (i != result.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";

    delete root;

    root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);

    updateTreeSums(root);

    result = implementationMapProblem7(root);

    std::cout << "Output = [";
    for (int i = 0; i < result.size(); ++i)
    {
        std::cout << result[i];
        if (i != result.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";

    delete root;
}


std::size_t implementationSetProblem1(std::vector<int> v, int size)
{
    std::set<int> s;

    for (int i = 0; i < size; ++i)
        s.insert(v[i]);

    return s.size();
}

int implementationSetProblem2(const std::string& jewels, const std::string& stones)
{
    std::set<char> s;

    for (char jewel : jewels)
        s.insert(jewel);

    int result = 0;

    for (char stone : stones)
        if (s.find(stone) != s.end())
            ++result;

    return result;
}

int implementationSetProblem3(const std::string& str, std::string& substr)
{
    int result = 0, left = 0, right = 0, lmax = 0;
    std::set<char> s;

    while (right < static_cast<int>(str.length()))
    {
        if (s.find(str[right]) == s.end())
        {
            s.insert(str[right]);
            if (right - left + 1 > result)
            {
                result = right - left + 1;
                lmax = left;
            }
            right++;
        }
        else
        {
            s.erase(str[left]);
            left++;
        }
    }

    substr = str.substr(lmax, result);

    return result;
}

int implementationMapProblem1(const std::string& str)
{
    std::map<char, int> mp;

    for (char ch : str)
        ++mp[ch];

    for (int i = 0; i < str.length(); ++i)
    {
        auto it = mp.find(str[i]);
        if (it->second == 1)
            return i;
    }

    return -1;
}

int implementationMapProblem2(const std::string& str, std::string& palindrome)
{
    std::map<char, int> mp;

    for (char ch : str)
        ++mp[ch];

    std::vector<char> PalindromeLetters;
    int result = 0;
    char middleOne = 0;
    bool middleTaken = false;

    for (std::pair<char, int> p : mp)
    {
        if (!middleTaken && p.second % 2)
        {
            middleOne = p.first;
            middleTaken = true;
        }

        int count = p.second / 2;
        result += count;

        for (int i = 0; i < count; ++i)
            PalindromeLetters.push_back(p.first);
    }

    result *= 2;

    if (middleOne)
    {
        PalindromeLetters.push_back(middleOne);
        ++result;
    }

    std::string tmp(PalindromeLetters.begin(), PalindromeLetters.end());
    palindrome = tmp;

    int saveSize = static_cast<int>(palindrome.size() - 1);
    for (int i = saveSize - 1; i >= 0; --i)
        palindrome += palindrome[i];

    return result;
}


bool implementationMapProblem3(const std::vector<int>& nums, int k)
{
    std::map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i)
    {
        auto it = mp.find(nums[i]);
        if (it != mp.end() && i - it->second <= k)
            return true;

        mp[nums[i]] = i;
    }

    return false;
}

bool implementationMapProblem4(const std::string& pattern, const std::string& s)
{
    std::map<std::string, char> mp;
    std::stringstream ss(s);
    std::string word;

    char c = 'a';
    std::string result{};
    while (ss >> word)
    {
        auto it = mp.find(word);
        if (it != mp.end())
            result += it->second;
        else
        {
            mp.insert(std::make_pair(word, c));
            result += c;
            c++;
        }
    }

    return result == pattern;
}

std::string implementationMapProblem5(const std::string& s)
{
    std::string result;
    std::map<char, int> mp;

    for (const char& c : s)
        ++mp[c];

    std::vector<std::pair<int, char>> v;

    for (std::pair<const char, int> &it : mp)
        v.emplace_back(it.second, it.first);

    std::sort(v.begin(), v.end(), std::greater<>());

    for (std::pair<int, char> elem : v)
        for (int i = 0; i < elem.first; ++i)
            result += elem.second;

    return result;
}

std::vector<int> implementationMapProblem7(TreeNode* root)
{
    std::map<int, int> mp;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        mp[q.front()->sum]++;

        if (q.front()->left)
            q.push(q.front()->left);

        if (q.front()->right)
            q.push(q.front()->right);

        q.pop();
    }

    std::vector<std::pair<int, int>> v;

    for (std::pair<const int, int> &it : mp)
        v.emplace_back(it.second, it.first);

    std::sort(v.begin(), v.end(), std::greater<>());

    std::vector<int> result;

    int last = v[0].first;
    for (std::pair<int, int> elem : v)
    {
        if (last != elem.first)
            break;
        result.push_back(elem.second);
    }

    return result;
}