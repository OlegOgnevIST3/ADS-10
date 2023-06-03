// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
      std::vector<std::vector<char>> permutation = tree.getpermutations();
    if (n > permutation.size()) return {};
    return permutation[n - 1];
}
