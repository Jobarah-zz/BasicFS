//
// Created by jobar on 2/2/2017.
//

#include <c++/fstream>
#include "BasicFileSystem.h"


bool BasicFileSystem::writeBlock(string diskName, int blockIndex, Block* block, int blockSize) {
    ofstream out;
    out.open(diskName, ios::out|ios::binary|ios::app);
    char * memBlock = (char*)calloc(1, blockSize);
    memcpy(memBlock, block, blockSize);
    out.seekp(blockIndex);
    out.write(memBlock, blockSize);
    delete [] memBlock;
    out.close();
    return false;
}
