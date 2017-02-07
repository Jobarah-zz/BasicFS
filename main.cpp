#include <iostream>
#include "DiskManager.h"

using namespace std;

int main () {
    DiskManager* dm = new DiskManager();
    dm->create("oaDisk", 2048, 512);
//    dm->allocateBlocks(20);
    dm->getFreeBlocks("oaDisk", 2048/512, 512);
    return 0;
}