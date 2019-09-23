#include "Tree.h"

//////////////////////////////////////
// Tree methods

// Add a single branch acting as a root branch when initialising
Tree::Tree(int _min_dist, int _max_dist, int width, int height) 
    : min_dist(_min_dist), max_dist(_max_dist), width(width), height(height) {

    Vector pos(width / 2, height);
    Vector dir(0, 0);
    Branch root(pos, dir);
    branches.push_back(root);
}

// Randmoly scatter points on a square envelope
void Tree::generateLeaves(int N)
{
    srand (static_cast <unsigned> (time(0)));
    for (int i = 0; i < N; i++)
    {
        float x = 0.0 + (rand() % (width * 6 / 10));
        float y = 0.0 + (rand() % (height * 6 / 10));
        Vector pos(x + (width * 2 / 10), y + (height * 2 / 10));
        leaves.push_back(Leaf(Vector(pos)));
    }
}

void Tree::grow()
{
    for (int j = 0; j < leaves.size(); j++)
    {
        Vector close_dir;
        float record = -1.0;
        int close_branch = -1;

	  // fine the closest branch to this leaf
        // and get the direction
        for (int i = 0; i < branches.size(); i++)
        {
            Vector dir = leaves[j].pos - branches[i].pos;
            float d = dir.getMag();

		// a leaf can be reached
            if (d < min_dist)
            {
                leaves[j].reached = true;
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

	  // if there's a branch within the radius of influence
	  // add the direction to that closest branch
        if (close_branch != -1)
        {
            close_dir.normalize();
            branches[close_branch].dir = branches[close_branch].dir
                                            + close_dir;
            branches[close_branch].counter++;
        }
    }

    // Remove leaves that have been reached
    for (int i = leaves.size()-1; i >= 0; i--)
    {
        if (leaves[i].reached)
            leaves.erase(leaves.begin() + i);
    }

    // Add new branches
    for (int i = branches.size()-1; i >= 0; i--)
    {
        Branch b = branches[i];
	  // In case branch is influenced by some leaves
	  // add a new branch accordingly
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

void Tree::show(){
    for (unsigned i = 0; i < leaves.size(); i++) {
        leaves[i].show();
    }

    for (unsigned i = 0; i < branches.size(); i++) {
        branches[i].show();
    }
}
