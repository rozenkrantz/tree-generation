#ifndef TREE_H
#define TREE_H

#include <cmath>
#include <vector>
#include "Tree.h"

#include <ctime>
#include <cstdlib>

const int INF = 1000000000;

namespace dequinox
{
	Tree::Tree(int N, int D) : N(N), D(D), image(500,500)
      {
      	Vector pos(250,0);
            Vector dir(0,0);
            Branch root(pos, dir);
            
		branches.push_back(root);
            generateLeaves();
      }

      Tree::~Tree()
	{
            image.write("sample.bmp");
      }

      void Tree::generateLeaves()
	{
            srand (static_cast <unsigned> (time(0)));
            
		for (int i = 0; i < N; i++){
                float x = 0.0 + (rand() % 400);
                float y = 0.0 + (rand() % 400);
                Vector pos(x + 50, y + 50);
                leaves.push_back(Leaf(pos));
            }
      }

      void Tree::grow()
	{
      	for (int j = 0; j < leaves.size(); j++)
		{
		      Vector close_dir;
                	float record = -1.0;
			int close_branch = -1;
		      
                	for (int i = 0; i < branches.size(); i++)
			{
                  	Vector dir = leaves[j].pos - branches[i].pos;
                    	float d = dir.getMag();
                    	
				if (d < min_dist) 
				{
                      		leaves[j].gotReached();
                      		close_branch = i;
                      		break;
                    	} 
				else if (d > max_dist) {} 
				else if (close_branch == -1 || d < record) 
				{
	                  	close_branch = i;
                      		close_dir = dir;
                      		record = d;
                    	}
                	}

                	if (close_branch != -1)
			{
                  	close_dir.normalize();
                    	branches[close_branch].dir = branches[close_branch].dir 
								   + closest_dir;
                    	branches[close_branch].counter++;
                	}
            }

            for (int i = leaves.size()-1; i >= 0; i--) 
		{            
	    		if (leaves[i].reached)
                    	leaves.erase(leaves.begin() + i);
		}

            for (int i = branches.size()-1; i >= 0; i--) 
		{
                	Branch b = branches[i];
                	if (b.counter > 0) 
			{
                  	b.dir = b.dir / (b.counter);
                    	b.dir.normalize();
                    	
				Branch newB = new Branch(b);
                    	branches.push_back(newB);
                    	b.reset();
                	}
            }
      }

      void Tree::show()
	{
            for (auto leaf : leaves)
		{
	            leaf.show(image);
            }

            for (Branch b : branches) 
		{
              	if (b.parent != nullptr)
                  	image.setLine(b.pos.x, b.pos.y, b.parent->pos.x, b.parent->pos.y, 255,255,255);
            }
      }
}

#endif // TREE_H
