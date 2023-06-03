// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <vector>

struct Node {
    char value;
    std::vector<Node*> children;
    explicit Node(char value_ = '\0'): value(value_) {}
};

class Tree {
 public:
    explicit Tree(const std::vector<char>& init):root(nullptr) {
        createPermutations(init);
    }
    std::vector<std::vector<char>> getPermutations() const {
        return permutations;
    }

 private:
    Node* root;
    std::vector<std::vector<char>> permutations;

    void createPermutations(const std::vector<char>& posl) {
        addChildren(root, posl);
        readTree(root, {});
    }

    void addChildren(Node* node, const std::vector<char>& posl) {
        if (node == nullptr) {
            root = node = new Node;
        }
        for (char value : posl) {
            Node* child = new Node(value);
            node->children.push_back(child);
            std::vector<char> updatedPosl(posl);
            updatedPosl.erase \
                (std::find(updatedPosl.begin(), updatedPosl.end(), value));
            addChildren(child, updatedPosl);
        }
    }

    void readTree(Node* node, std::vector<char> posl) {
        if (node != nullptr && node->value != '\0') posl.push_back(node->value);
        if (node->children.empty()) permutations.push_back(posl);
        for (Node* child : node->children) {
            readTree(child, posl);
        }
    }
};
#endif  // INCLUDE_TREE_H_
