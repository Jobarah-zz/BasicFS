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

Block BasicFileSystem::readBlock(string diskName, int i, int blockSize) {
    ifstream in(diskName,ios::in|ios::binary|ios::ate);
    Block *returnBlock;
    int size = in.tellg();
    in.seekg(0);
    char *readBlock;
    in.read(readBlock, blockSize);
    returnBlock = (Block*)readBlock;
    in.close();
    return *returnBlock;
}