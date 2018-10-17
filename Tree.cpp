#include <iostream>
#include "Tree.h"

namespace dequinox
{
    void log()
    {
        std::cout << " ";
    }

    template<typename Head, typename... Tail>
    void log(Head H, Tail... T)
    {
        std::cout << H << " ";
        log(T...);
    }

    Tree::Tree(int min_dist, int max_dist, int width, int height) : max_dist(max_dist), min_dist(min_dist), width(width), height(height), image(width,height)
    {
        Vector pos(width / 2, 0);
        Vector dir(0,0);
        Branch root(pos, dir);
        branches.push_back(root);
    }

    Tree::~Tree()
    {
        image.write("facesample4.bmp");
    }


    void Tree::generateLeaves(std::string filename)
    {
        Bitmap img(filename);
        int w = img.getWidth();
        int h = img.getHeight();
        srand (static_cast <unsigned> (time(0)));

        for (int i = 2; i < width - 1; i++)
        {
            for (int j = 2; j < height - 1; j++)
            {
                uint8_t *pPixel = img.getPixel(i, j);
                int rnd = rand() % 10;

                if (((int)pPixel[0] + (int)pPixel[1] + (int)pPixel[2]) / 3 < 30 && !rnd)
                {
                    Vector pos(i * 1.0, j * 1.0);
                    leaves.push_back(Leaf(pos));
                }
            }
        }
    }

    void Tree::generateLeaves(int N)
    {
        srand (static_cast <unsigned> (time(0)));
        for (int i = 0; i < N; i++)
        {
            float x = 0.0 + (rand() % (width * 6 / 10));
            float y = 0.0 + (rand() % (height * 6 / 10));
            Vector pos(x + (width * 2 / 10), y + (height * 2 / 10));
            leaves.push_back(Leaf(pos));
        }
    }

    bool Tree::grow()
    {
        log("LSIZE:", leaves.size(), "BSIZE:", branches.size(), "\n");

        for (int j = 0; j < leaves.size(); j++)
        {
            if (!leaves[j].reached)
            {
                int closest_branch = -1;
                Vector closest_dir;
                float record = -1.0;

                for (int i = 0; i < branches.size(); i++)
                {
                    Vector dir = leaves[j].pos - branches[i].pos;
                    float d = dir.getMag();

                    if (d < min_dist)
                    {
                        leaves[j].gotReached();
                        closest_branch = i;
                        break;
                    }
                    else if (d > max_dist) {}
                    else if (closest_branch == -1 || d < record)
                    {
                        closest_branch = i;
                        closest_dir = dir;
                        record = d;
                    }
                }

                if (closest_branch != -1)
                {
                    closest_dir.normalize();
                    branches[closest_branch].dir = branches[closest_branch].dir + closest_dir;
                    branches[closest_branch].counter++;
                }
            }
        }

        bool newAdded = false;
        for (int i = branches.size()-1; i >= 0; i--)
        {
            Branch b = branches[i];
            if (branches[i].counter > 0)
            {
                //branches[i].dir = branches[i].dir / (branches[i].counter);
                branches[i].dir.normalize();
                Branch newB = new Branch(branches[i]);
                branches.push_back(newB);
                b.reset();
                newAdded = true;
            }
        }
        return newAdded;
    }

    void Tree::show()
    {
        log("SHOWING LEAVES...");
        for (l : leaves)
            image.circle(l.pos.x, l.pos.y, 3, 0, 255, 0);

        log("DONE\n", "SETTING LINES...");
        for (b : branches)
            if (b.parent != nullptr)
                image.setLine(b.pos.x, b.pos.y, b.parent->pos.x, b.parent->pos.y, 255,255,255);

        log("DONE\n");
    }
}
