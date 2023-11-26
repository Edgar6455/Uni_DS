#ifndef SET_MAP_TRIE_H
#define SET_MAP_TRIE_H

#include <map>
#include <string>

class Trie
{
private:
    class TrieNode
    {
    public:
        std::map<char, TrieNode*> child;
        bool isEndOfWord;

        TrieNode()
        {
            isEndOfWord = false;
        }
    };

    void destroyTrie(TrieNode* node)
    {
        for (auto& pair : node->child)
        {
            destroyTrie(pair.second);
        }
        delete node;
    }

    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        destroyTrie(root);
    }

    void insert(const std::string &word)
    {
        TrieNode *current = root;
        for (char ch: word) {
            if (current->child.find(ch) == current->child.end())
            {
                current->child[ch] = new TrieNode();
            }
            current = current->child[ch];
        }
        current->isEndOfWord = true;
    }

    bool startsWith(const std::string &prefix)
    {
        TrieNode *current = root;
        for (char ch : prefix)
        {
            if (current->child.find(ch) == current->child.end())
            {
                return false;
            }
            current = current->child[ch];
        }

        return true;
    }
};

#endif //SET_MAP_TRIE_H