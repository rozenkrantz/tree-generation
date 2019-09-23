#include "Branch.h"
#include <stdio.h>

//////////////////////////////////////
// Leaf methods

Branch::Branch(Vector p, Vector d) : pos(p), dir(d) {}

Branch::Branch(Branch *p){
    parent = p;
    pos = parent->next();
    dir = parent->dir;
    saveDir = dir;
}

void Branch::operator=(const Branch &o){
	pos = o.pos;
	dir = o.dir;
	parent = o.parent;
    counter = o.counter;
    len = o.len;
    saveDir = o.saveDir;
}

void Branch::reset(){
    counter = 0;
    dir = saveDir;
}

// Return a vector pointing to the direction
Vector Branch::next() const {
	Vector v = dir * len;
	Vector next = pos + v;
	return next;
}

void Branch::show() {
    if (parent != NULL) {
        ofDrawLine(parent->pos.x, parent->pos.y, pos.x, pos.y);
    }
}
