//
// Created by jobar on 2/2/2017.
//

#include <fstream>
#include "BasicFileSystem.h"
#include <iostream>

using namespace std;
bool BasicFileSystem::writeBlock(string diskName, int blockNumber, Block* block, int blockSize) {
    ofstream out;
    out.open(diskName, ios::out|ios::binary|ios::app);
    char * memBlock = (char*)calloc(1, blockSize);
    memcpy(memBlock, block, blockSize);
    out.seekp(blockNumber * blockSize);
    out.write(memBlock, blockSize);
    delete [] memBlock;
    out.close();
    return false;
}

Block BasicFileSystem::readBlock(string diskName, int blockNumber, int blockSize) {
    ifstream in(diskName,ios::in|ios::binary|ios::ate);
    Block *returnBlock;
    in.seekg(blockNumber * blockSize);
    char *readBlock;
    in.read(readBlock, blockSize);
    returnBlock = (Block*)readBlock;
    in.close();
    return *returnBlock;
}