#include <iostream>
#include "bin_tree.h"
using namespace std;

void MyPrint(void* params){
    std::cout << "Hello!" << endl;
}


int main(int argc, char *argv[]){

    BinTree<int> binTree ;

    binTree.add(20);
    binTree.add(30);
    binTree.add(10);
    binTree.add(5);
    binTree.add(15);
    binTree.add(8);
    binTree.add(1);
    binTree.add(7);
    binTree.add(9);

    void* params;

    binTree.traversal(MyPrint, params);

    binTree.remote(10);

    std::cout << "Remote: " << std::endl;

    binTree.traversal(MyPrint, params);
    return 0;
}
