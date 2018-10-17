#ifndef TREE_H
#define TREE_H

#include <ctime>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "Leaf.h"
#include "Branch.h"
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

namespace dequinox
{
    class Tree
    {
        private:
            int width{800};
            int height{800};
            float max_dist{100};
            float min_dist{20};

            Bitmap image;
            std::vector<Branch> branches;
            std::vector<Leaf> leaves;

        public:
            Tree(int min_dist, int max_dist, int width, int height);
            ~Tree();

            bool grow();
            void show();
            void generateLeaves(std::string filename);
            void generateLeaves(int N);
    };
}

#endif // TREE_H
