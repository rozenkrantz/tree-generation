#ifndef LEAF_H
#define LEAF_H

#include "Vector.h"

namespace dequinox
{
    struct Leaf
    {
        bool reached{false};
        Vector pos;

        Leaf(Vector pos) : pos(pos) {}

        void gotReached()
        {
            reached = true;
        }

        Vector getPos()
        {
            return pos;
        }
    };
}

#endif // LEAF_H
