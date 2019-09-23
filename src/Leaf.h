#ifndef LEAF_H
#define LEAF_H

#include "Vector.h"
#include "ofMain.h"

struct Leaf {
    bool reached{false};
    Vector pos;

    Leaf(Vector pos);
    void show();
};

#endif // LEAF_H