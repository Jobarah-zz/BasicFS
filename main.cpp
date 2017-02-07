// writing on a text file
#include <iostream>
#include <fstream>
#include "DiskManager.h"

using namespace std;

int main () {
    DiskManager* dm = new DiskManager();
    dm->create("oaDisk", 2048, 512);
//    dm->allocateBlocks(20);
    return 0;
}