#ifndef TREE_H
#define TREE_H

#include <vector>
#include "Leaf.h"
#include "Branch.h"
#include "Vector.h"

class Tree {
    public:
        Tree(int min_dist, int max_dist, int width, int height);
        void generateLeaves(int N);
        void show();
        void grow();
    private:
        int width{800};
        int height{800};
        float max_dist{100};
        float min_dist{20};
        std::vector<Leaf> leaves;
        std::vector<Branch> branches;
};

#endif // TREE_H