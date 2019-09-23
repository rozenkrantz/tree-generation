#include "Leaf.h"

//////////////////////////////////////
// Leaf methods

Leaf::Leaf(Vector pos) : pos(pos) {}

void Leaf::show() {
    ofDrawCircle(pos.x, pos.y, 3);
}
