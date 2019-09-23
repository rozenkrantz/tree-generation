#ifndef BRANCH_H
#define BRANCH_H

#include "Vector.h"
#include "ofMain.h"

struct Branch {
    float len{5};
    int16_t counter{0};
    Vector pos{0,0};
    Vector dir{0,0};
    Vector saveDir{0,0};
    Branch *parent{nullptr};

    Branch(Vector p, Vector d);
    Branch(Branch *p);
    void operator=(const Branch &o);
    void reset();
    Vector next() const;
    void show();
};

#endif // BRANCH_H
