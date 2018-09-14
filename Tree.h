#ifndef TREE_H
#define TREE_H

#include <cmath>
#include <vector>
#include "Leaf.h"
#include "Vector.h"
#include "Branch.h"
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

#include <ctime>
#include <cstdlib>

namespace dequinox
{
	class Tree
    	{
      	private:
		      int N{0};
		      int D{0};
		      std::vector<Branch> branches;
		      std::vector<Leaf> leaves;
		      Bitmap image;
		      float max_dist{5000};
		      float min_dist{1};
    		public:
        		Tree(int N, int D);
			void generateLeaves();
			void grow();
        		void show();
			~Tree();  		          	
	};
}

#endif // TREE_H
