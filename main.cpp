#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    dequinox::Tree tree(500, 10);
    for (int i = 0; i < 100; i++){
        tree.grow();
    }
    tree.show();
    cout << "Hello world!" << endl;
    return 0;
}
